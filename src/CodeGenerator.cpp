#include <vector>

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/ValueSymbolTable.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetSelect.h"

#include "CodeGenerator.h"
#include "AbstractSyntaxTree.h"
#include "TranslationUnitNode.h"
#include "DeclarationNode.h"
#include "FunctionNode.h"
#include "StatementNode.h"
#include "ExpressionNode.h"
#include "OperatorNode.h"
#include "ConstantNode.h"
#include "TypeNode.h"
#include "Utility.h"

//===------------------------------------------------------------===//
// Auxiliary Function
//===------------------------------------------------------------===//

llvm::Value *LogErrorV(const char *str) {
  fprintf(stderr, "CodeGen Error : %s\n", str);
  return nullptr;
}

void Info(const char *str) {
  fprintf(stdout, "Info : %s\n", str);
}

llvm::AllocaInst *CreateEntryBlockAlloca(llvm::Function * function, llvm::StringRef varName, llvm::Type *type) {
    llvm::IRBuilder<> Tmp(&function->getEntryBlock(), function->getEntryBlock().begin());
    return Tmp.CreateAlloca(type, nullptr, varName);
}

//===------------------------------------------------------------===//
// Code Generation
//===------------------------------------------------------------===//

llvm::Value *TranslationUnitNode::CodeGen(CodeGenerator *generator) {

    Info("[NODE] Translation Unit Node");

    /* Create Global Initialization Function */
    llvm::FunctionType *funcType = llvm::FunctionType::get(generator->builder.getVoidTy(), false);
    llvm::Function *function = llvm::Function::Create(funcType,
                                                      llvm::Function::InternalLinkage,
                                                      "GlobalInit",
                                                      &generator->module);
    llvm::BasicBlock *funcBody = llvm::BasicBlock::Create(generator->context, "initialize", function);

    generator->JumpToBlock(funcBody);
    llvm::ReturnInst *ret = generator->builder.CreateRetVoid();
    generator->JumpToVoid();
    generator->SetGlobalInsertionPoint(ret);

    /* Start Generating Code */
    generator->AddNewTable();
    for (auto def : definitions) def->CodeGen(generator);
    generator->RemoveTable();

    return nullptr;
}

llvm::Value *FunctionNode::CodeGen(CodeGenerator *generator) {

    Info("[NODE] Function Node");
    
    /* Get Parameter Definition */
    std::vector<llvm::Type*> paramTypes;
    std::vector<std::string> paramNames;
    for(auto param : parameters->parameters) {
        paramTypes.push_back(generator->ConvertToLLVMType(param->GetType()));
        paramNames.push_back(param->GetName());
    }

    /* Construct Function Node */
    Type retType = returnType->GetType();
    llvm::FunctionType *funcType = llvm::FunctionType::get(generator->ConvertToLLVMType(retType), paramTypes, false);
    llvm::Function *function = llvm::Function::Create(funcType,
                                                      llvm::Function::ExternalLinkage,
                                                      name->GetName(),
                                                      &generator->module);
    llvm::BasicBlock *funcBody = llvm::BasicBlock::Create(generator->context, "", function);
    generator->JumpToBlock(funcBody);

    /* Set Argument Names and Add to Value Table */
    generator->AddNewTable();
    unsigned int i = 0;
    for (auto &arg : function->args()) {
        arg.setName(paramNames[i]);
        llvm::AllocaInst *alloc = generator->builder.CreateAlloca(paramTypes[i], nullptr, paramNames[i]);
        generator->builder.CreateStore(&arg, alloc);
        generator->RecordValue(paramNames[i], alloc);
        i++;
    }

    /* Generate Function Body */
    body->CodeGen(generator);

    /* Generate Default Return Instruction */
    if(retType == Type::VOID) {
        generator->builder.CreateRetVoid();
    } else {
        generator->builder.CreateRet(generator->GetTypeDefaultValue(retType));
    }

    /* Finish up */
    generator->JumpToVoid();
    generator->RemoveTable();

    /* Validate Function */
    verifyFunction(*function);
    return function;
}

llvm::Value *ParameterListNode::CodeGen(CodeGenerator *generator) {
    return nullptr;
}

llvm::Value *DeclarationNode::CodeGen(CodeGenerator *generator) {
    
    Info("[NODE] Declaration Node");

    std::string dname = std::string(name->GetName());
    Type dtype = type->GetType();

    llvm::Value *var = nullptr;

    /* Local Varible */
    if(generator->builder.GetInsertBlock()) {

        var = generator->builder.CreateAlloca(generator->ConvertToLLVMType(dtype), nullptr, dname);

        if (initValue) {
            llvm::Value *R = initValue->CodeGen(generator);
            R = generator->CastValueType(R, initValue->GetValueType(), dtype);
            generator->builder.CreateStore(R, var);
        }
    }

    /* Global Varible */
    else {
        var = new llvm::GlobalVariable(generator->module,
                                       generator->ConvertToLLVMType(type->GetType()),
                                       false,
                                       llvm::GlobalValue::ExternalLinkage,
                                       generator->GetTypeDefaultValue(type->GetType()),
                                       dname);

        if (initValue) {
            generator->JumpToInitializer();
            llvm::Value *R = initValue->CodeGen(generator);
            R = generator->CastValueType(R, initValue->GetValueType(), dtype);
            generator->builder.CreateStore(R, var);
            generator->JumpToVoid();
        }
    }

    generator->RecordValue(dname, var);
    
    return nullptr;
}

llvm::Value *EmptyExpressionNode::CodeGen(CodeGenerator *generator) {
    return nullptr;
}

llvm::Value *CompoundStatementNode::CodeGen(CodeGenerator *generator) {
    
    Info("[NODE] Compound Statement Node");

    generator->AddNewTable();
    for (auto item : items) item->CodeGen(generator);
    generator->RemoveTable();

    return nullptr;
}

llvm::Value *ExpressionStatementNode::CodeGen(CodeGenerator *generator) {
    
    Info("[NODE] Expression Statement Node");

    expression->CodeGen(generator);

    return nullptr;
}

llvm::Value *IfStatementNode::CodeGen(CodeGenerator *generator) {
    
    Info("[NODE] If Statement Node");

    // Create Basic Blocks
    llvm::BasicBlock *thenBlock = generator->CreateBasicBlock("if-then");
    llvm::BasicBlock *elseBlock = generator->CreateBasicBlock("if-else");
    llvm::BasicBlock *afterBlock = generator->CreateBasicBlock("after-if");

    // Generate Condition Branch Instructions
    llvm::Value *condValue = condition->CodeGen(generator);
    condValue = generator->CastValueType(condValue, condition->GetValueType(), Type::BOOLEAN);
    generator->builder.CreateCondBr(condValue, thenBlock, elseBlock);

    // Complete Then Block
    generator->JumpToBlock(thenBlock);
    thenStmt->CodeGen(generator);
    generator->builder.CreateBr(afterBlock);

    // Complete Then Block
    generator->JumpToBlock(elseBlock);
    elseStmt->CodeGen(generator);
    generator->builder.CreateBr(afterBlock);

    // Finish up
    generator->JumpToBlock(afterBlock);

    return nullptr;
}

llvm::Value *WhileStatementNode::CodeGen(CodeGenerator *generator) {
    
    Info("[NODE] While Statement Node");

    // Create Basic Blocks
    llvm::BasicBlock *condBlock = generator->CreateBasicBlock("whlie-cond");
    llvm::BasicBlock *loopBlock = generator->CreateBasicBlock("while-loop");
    llvm::BasicBlock *afterBlock = generator->CreateBasicBlock("after-while");

    // Complete Loop Condition Branch
    generator->JumpToBlock(condBlock);
    llvm::Value *condValue = condition->CodeGen(generator);
    condValue = generator->CastValueType(condValue, condition->GetValueType(), Type::BOOLEAN);
    generator->builder.CreateCondBr(condValue, loopBlock, afterBlock);

    // Complete Loop Body
    generator->JumpToBlock(loopBlock);
    body->CodeGen(generator);
    generator->builder.CreateBr(condBlock);

    // Finish up
    generator->JumpToBlock(afterBlock);

    return nullptr;
}

llvm::Value *ForStatementNode::CodeGen(CodeGenerator *generator) {
    
    Info("[NODE] For Statement Node");

    // Generate IR for Initial Statement
    generator->AddNewTable();
    init->CodeGen(generator);

    // Create Basic Blocks
    llvm::BasicBlock *condBlock = generator->CreateBasicBlock("for-cond");
    llvm::BasicBlock *loopBlock = generator->CreateBasicBlock("for-loop");
    llvm::BasicBlock *afterBlock = generator->CreateBasicBlock("after-for");

    // Complete Loop Condition Branch
    generator->JumpToBlock(condBlock);
    llvm::Value *condValue = condition->CodeGen(generator);
    condValue = generator->CastValueType(condValue, condition->GetValueType(), Type::BOOLEAN);
    generator->builder.CreateCondBr(condValue, loopBlock, afterBlock);

    // Complete Loop Body
    generator->JumpToBlock(loopBlock);
    body->CodeGen(generator);
    generator->builder.CreateBr(condBlock);
    loop->CodeGen(generator);

    // Finish up
    generator->JumpToBlock(afterBlock);
    generator->RemoveTable();

    return nullptr;
}

llvm::Value *ReturnStatementNode::CodeGen(CodeGenerator *generator) {
    
    Info("[NODE] Return Statement Node");

    if(NOT_NULL_OF_TYPE(expression, EmptyExpressionNode*)) {
        generator->builder.CreateRetVoid();
    } else {
        generator->builder.CreateRet(expression->CodeGen(generator));
    }

    return nullptr;
}


llvm::Value *FunctionCallNode::CodeGen(CodeGenerator *generator) {

    Info("[NODE] Function Call Node");

    llvm::Function *function = generator->module.getFunction(std::string(name->GetName()));

    std::vector<llvm::Value *> args;
    for(auto arg : arguments->arguments) {
        args.push_back(arg->CodeGen(generator));
    }

    return generator->builder.CreateCall(function, args, "call");
}

llvm::Value *ArgumentListNode::CodeGen(CodeGenerator *generator) {
    return nullptr;
}

llvm::Value *BinaryOpNode::CodeGen(CodeGenerator *generator) {
    
    Info("[NODE] Binary Operation Node");

    llvm::Value *L = leftOperand->CodeGen(generator);
    llvm::Value *R = rightOperand->CodeGen(generator);

    assert(L != nullptr && R != nullptr);

    Type leftType = leftOperand->GetValueType();
    Type rightType = rightOperand->GetValueType();
    Type opType = TypeUtils::GetPromotedTypeBetween(leftType, rightType);

    /* Cast Operands */

    /* Downcast to BOOLEAN if Logical Operation */
    if(IsLogicalOperator()) {
        L = generator->CastValueType(L, leftType, Type::BOOLEAN);
        R = generator->CastValueType(R, rightType, Type::BOOLEAN);
    }

    /* Upcast from BOOLEAN to INTEGER if Integer Operation
     * or Relational Operation with at Least 1 Interger Operands and no Float Operands
     * or Arithmetic Operation with Non-float Operands */
    else if(opType == Type::INTEGER || valueType == Type::INTEGER) {
        L = generator->CastValueType(L, leftType, Type::INTEGER);
        R = generator->CastValueType(R, rightType, Type::INTEGER);
    }

    /* Upcast to Float if Arithmetic/Relational Operation with at Least 1 Float Operands */
    else if (opType == Type::FLOAT) {
        L = generator->CastValueType(L, leftType, Type::FLOAT);
        R = generator->CastValueType(R, rightType, Type::FLOAT);
    }

    /* Compute Result */
    llvm::Value *res = nullptr;
    switch(op) {

        case Operator::ADD: {

            res = valueType == Type::FLOAT ? generator->builder.CreateFAdd(L, R, "faddtmp")
                : generator->builder.CreateAdd(L, R, "iaddtmp");
            break;

        }
        case Operator::SUB: {

            res = valueType == Type::FLOAT ? generator->builder.CreateFSub(L, R, "fsubtmp")
                : generator->builder.CreateSub(L, R, "isubtmp");
            break;

        }
        case Operator::MUL: {
        
            res = valueType == Type::FLOAT ? generator->builder.CreateFMul(L, R, "fmultmp")
                : generator->builder.CreateMul(L, R, "imultmp");
            break;

        }
        case Operator::DIV: {
        
            res = valueType == Type::FLOAT ? generator->builder.CreateFDiv(L, R, "fdivtmp")
                : generator->builder.CreateSDiv(L, R, "idivtmp");
            break;

        }
        case Operator::MOD: {

            res = generator->builder.CreateSRem(L, R, "modtmp");
            break;

        }
        case Operator::AND: {

            res = generator->builder.CreateAnd(L, R, "andtmp");
            break;

        }
        case Operator::OR: {

            res = generator->builder.CreateOr(L, R, "ortmp"); 
            break;

        }
        case Operator::XOR: {

            res = generator->builder.CreateXor(L, R, "xortmp"); 
            break;

        }
        case Operator::EQ: {

            res = opType == Type::FLOAT ? generator->builder.CreateFCmpOEQ(L, R, "feqtmp")
                : generator->builder.CreateICmpEQ(L, R, "ieqtmp");
            break;

        }
        case Operator::NEQ: {

            res = opType == Type::FLOAT ? generator->builder.CreateFCmpONE(L, R, "fnetmp")
                : generator->builder.CreateICmpNE(L, R, "inetmp");
            break;

        }
        case Operator::GT: {

            res = opType == Type::FLOAT ? generator->builder.CreateFCmpOGT(L, R, "fgttmp")
                : generator->builder.CreateICmpSGT(L, R, "igttmp");
            break;
        
        }
        case Operator::GTE: {

            res = opType == Type::FLOAT ? generator->builder.CreateFCmpOGE(L, R, "fgetmp")
                : generator->builder.CreateICmpSGE(L, R, "igetmp");
            break;
        
        }
        case Operator::LT: {

            res = opType == Type::FLOAT ? generator->builder.CreateFCmpOLT(L, R, "flttmp")
                : generator->builder.CreateICmpSLT(L, R, "ilttmp");
            break;
        
        }
        case Operator::LTE: {

            res = opType == Type::FLOAT ? generator->builder.CreateFCmpOLE(L, R, "fletmp")
                : generator->builder.CreateICmpSLE(L, R, "iletmp");
            break;

        }
        case Operator::LOGAND: {

            res = generator->builder.CreateLogicalAnd(L, R, "logicandtmp");
            break;

        }
        case Operator::LOGOR: {

            res = generator->builder.CreateLogicalOr(L, R, "logicortmp");
            break;

        }
    }

    assert(res != nullptr);
    return res;
}

llvm::Value *AssignOpNode::CodeGen(CodeGenerator *generator) {

    Info("[NODE] Assignment Node");
    
    llvm::Value *L = generator->FindValue(std::string(leftValue->GetName()));
    assert(L != nullptr);

    llvm::Value *R = rightValue->CodeGen(generator);
    R = generator->CastValueType(R, rightValue->GetValueType(), valueType);

    generator->builder.CreateStore(R, L);
    return R;
}

llvm::Value *IdentifierNode::CodeGen(CodeGenerator *generator) {
    llvm::Value *value = generator->FindValue(std::string(id));
    assert(value != nullptr);

    return generator->builder.CreateLoad(generator->ConvertToLLVMType(valueType), value, "loadtmp");
}

llvm::Value *IntegerNode::CodeGen(CodeGenerator *generator) {
    return llvm::ConstantInt::get(generator->builder.getInt32Ty(), num);
}

llvm::Value *FloatNode::CodeGen(CodeGenerator *generator) {
    return llvm::ConstantFP::get(generator->builder.getDoubleTy(), num);
}

llvm::Value *TypeNode::CodeGen(CodeGenerator *generator) {
    return nullptr;
}

//===------------------------------------------------------------===//
// Top-Level Initialize & Generate
//===------------------------------------------------------------===//

void CodeGenerator::InitializeLLVM() {
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();
}

void CodeGenerator::PrintIR() {
    module.print(llvm::outs(), nullptr);
}

llvm::Type *CodeGenerator::ConvertToLLVMType(Type type) {
    switch (type)
    {
        case Type::INTEGER: return llvm::Type::getInt32Ty(context);
        case Type::FLOAT: return llvm::Type::getDoubleTy(context);
        case Type::VOID: return llvm::Type::getVoidTy(context);
        default: return nullptr;
    }
}

llvm::Type *CodeGenerator::ConvertToLLVMPtrType(Type type) {
    switch (type)
    {
        case Type::INTEGER: return llvm::Type::getInt32PtrTy(context);
        case Type::FLOAT: return llvm::Type::getDoublePtrTy(context);
        case Type::VOID: return llvm::Type::getInt32PtrTy(context);
        default: return nullptr;
    }
}

llvm::Constant *CodeGenerator::GetTypeDefaultValue(Type type) {
    switch(type) {
        // TO DO : analyze int a = 1 + b * 3; Type::VOID
        case Type::INTEGER: return llvm::ConstantInt::get(builder.getInt32Ty(), 0);
        case Type::FLOAT: return llvm::ConstantFP::get(builder.getDoubleTy(), 0.0);
        case Type::VOID: return nullptr;
        default: return nullptr;
    }
}

llvm::Value *CodeGenerator::CastValueType(llvm::Value *origin, Type from, Type to) {

    switch(to) {

        case Type::BOOLEAN:
            switch(from) {
                case Type::BOOLEAN: return origin;
                case Type::INTEGER: return builder.CreateICmpNE(origin, builder.getInt32(0), "bcasttmp");
                case Type::FLOAT: return builder.CreateFCmpONE(origin, llvm::ConstantFP::get(builder.getDoubleTy(), 0.0), "bcasttmp");
            }

        case Type::INTEGER:
            switch(from) {
                case Type::BOOLEAN: return builder.CreateIntCast(origin, builder.getInt32Ty(), false, "icasttmp");
                case Type::INTEGER: return origin;
                case Type::FLOAT: return builder.CreateFPToSI(origin, builder.getInt32Ty(), "icasttmp");
            }

        case Type::FLOAT:
            switch(from) {
                case Type::BOOLEAN: return builder.CreateUIToFP(origin, builder.getDoubleTy(), "fcasttmp");
                case Type::INTEGER: return builder.CreateSIToFP(origin, builder.getDoubleTy(), "fcasttmp");
                case Type::FLOAT: return origin;
            }

    }

    assert(false);
}
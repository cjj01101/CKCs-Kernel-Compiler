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
    for (auto def : definitions) def->CodeGen(generator);
    return nullptr;
}

llvm::Value *FunctionNode::CodeGen(CodeGenerator *generator) {

    Info("[NODE] Function Node");
    
    // Get Parameter Definition.
    std::vector<llvm::Type*> paramTypes;
    std::vector<std::string> paramNames;
    for(auto param : parameters->parameters) {
        paramTypes.push_back(generator->ConvertToLLVMType(param->GetType()));
        paramNames.push_back(param->GetName());
    }

    // Construct Function Node.
    Type retType = returnType->GetType();
    llvm::FunctionType *funcType = llvm::FunctionType::get(generator->ConvertToLLVMType(retType), paramTypes, false);
    llvm::Function *function = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name->GetName(), &generator->module);

    // Set Argument Names.
    unsigned int i = 0;
    for (auto &arg : function->args()) arg.setName(paramNames[i++]);
    
    // Record the function arguments in the NamedValues map.
    //NamedValues.clear();
    //for (auto &arg : function->args()) NamedValues[std::string(arg.getName())] = &arg;

    // Generate Function Body.
    llvm::BasicBlock *funcBody = llvm::BasicBlock::Create(generator->context, "", function);
    generator->builder.SetInsertPoint(funcBody);
    body->CodeGen(generator);

    // Generate Default Return Instruction
    if(retType == Type::VOID) {
        generator->builder.CreateRetVoid();
    } else {
        generator->builder.CreateRet(generator->GetTypeDefaultValue(retType));
    }

    // Validate the generated code, checking for consistency.
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

    llvm::Value *res = nullptr;
    
    /*if (this->isGlobal) {
        res = new llvm::GlobalVariable(*generator->module, TypeNode::ConvertToLLVMType(type->GetType()), true,
                                        llvm::GlobalValue::ExternalLinkage, TypeNode::initValue(type->GetType()), DecName);
        if (initValue) res = generator->builder.CreateStore(initValue->CodeGen(), res);
    }
    else {
        res = CreateEntryBlockAlloca(, this->type->toLLVMPtrType);
        
    }*/

    res = generator->builder.CreateAlloca(generator->ConvertToLLVMType(dtype), nullptr, dname);
    if (initValue) res = generator->builder.CreateStore(initValue->CodeGen(generator), res);
    
    return res;
}

llvm::Value *CompoundStatementNode::CodeGen(CodeGenerator *generator) {
    
    for (auto item : items) item->CodeGen(generator);

    return nullptr;
}

llvm::Value *ExpressionStatementNode::CodeGen(CodeGenerator *generator) {
    
    expression->CodeGen(generator);

    return nullptr;
}

llvm::Value *IfStatementNode::CodeGen(CodeGenerator *generator) {
    
    condition->CodeGen(generator);
    thenStmt->CodeGen(generator);
    elseStmt->CodeGen(generator);

    return nullptr;
}

llvm::Value *WhileStatementNode::CodeGen(CodeGenerator *generator) {
    
    condition->CodeGen(generator);
    body->CodeGen(generator);

    return nullptr;
}

llvm::Value *ForStatementNode::CodeGen(CodeGenerator *generator) {
    
    init->CodeGen(generator);
    condition->CodeGen(generator);
    loop->CodeGen(generator);
    body->CodeGen(generator);

    return nullptr;
}

llvm::Value *ReturnStatementNode::CodeGen(CodeGenerator *generator) {
    
    exprStmt->CodeGen(generator);

    return nullptr;
}

llvm::Value *EmptyExpressionNode::CodeGen(CodeGenerator *generator) {
    return nullptr;
}


llvm::Value *FunctionCallNode::CodeGen(CodeGenerator *generator) {

    llvm::Function *function = generator->module.getFunction(std::string(name->GetName()));

    std::vector<llvm::Value *> args;
    for(auto arg : arguments->arguments) {
        args.push_back(arg->CodeGen(generator));
    }

    return generator->builder.CreateCall(function, args, "call");
}

llvm::Value *ArgumentListNode::CodeGen(CodeGenerator *generator) {
    //for (auto arg : arguments) arg->CodeGen(generator);
    return nullptr;
}

llvm::Value *BinaryOpNode::CodeGen(CodeGenerator *generator) {
    llvm::Value *L = leftOperand->CodeGen(generator);
    llvm::Value *R = rightOperand->CodeGen(generator);

    // if (!L || !R)  return nullptr;

    Type leftType = leftOperand->GetValueType();
    Type rightType = rightOperand->GetValueType();
    Type opType = TypeNode::GetPromotedTypeBetween(leftType, rightType);

    // Downcast to INT if Logical Operator
    if(op == Operator::LOGAND || op == Operator::LOGOR) {
        opType = Type::INTEGER;
        if(leftType == Type::FLOAT){
            L = generator->builder.CreateFPToSI(L, generator->builder.getInt32Ty(), "cast float to int");
        }
        if(rightType == Type::FLOAT){
            R = generator->builder.CreateFPToSI(R, generator->builder.getInt32Ty(), "cast float to intt");
        }
    }

    // Upcast if Necessary
    if(opType == Type::FLOAT) {
        if(leftType == Type::INTEGER){
            L = generator->builder.CreateSIToFP(L, generator->builder.getDoubleTy(), "cast int to float");
        }
        if(rightType == Type::INTEGER){
            R = generator->builder.CreateSIToFP(R, generator->builder.getDoubleTy(), "cast int to float");
        }
    }

    switch(op) {
        case Operator::ADD: 
            switch(opType) {
                case Type::INTEGER: return generator->builder.CreateAdd(L, R, "iadd");
                case Type::FLOAT: return generator->builder.CreateFAdd(L, R, "fadd");
            }

        case Operator::SUB:
            switch(opType) {
                case Type::INTEGER: return generator->builder.CreateSub(L, R, "isub");
                case Type::FLOAT: return generator->builder.CreateFSub(L, R, "fsub");
            }
        
        case Operator::MUL: 
            switch(opType) {
                case Type::INTEGER: return generator->builder.CreateMul(L, R, "imul");
                case Type::FLOAT: return generator->builder.CreateFMul(L, R, "fmul");
            }

        case Operator::DIV:
            switch(opType) {
                case Type::INTEGER: return generator->builder.CreateSDiv(L, R, "idiv");
                case Type::FLOAT: return generator->builder.CreateFDiv(L, R, "fdiv");
            }

        case Operator::MOD: return generator->builder.CreateSRem(L, R, "mod");

        case Operator::AND: return generator->builder.CreateAnd(L, R, "and");
        case Operator::OR:  return generator->builder.CreateOr(L, R, "or");
        case Operator::XOR: return generator->builder.CreateXor(L, R, "xor");

        case Operator::EQ: 
            switch(opType) {
                case Type::INTEGER: return generator->builder.CreateICmpEQ(L, R, "ieq");
                case Type::FLOAT: return generator->builder.CreateFCmpOEQ(L, R, "feq");
            }

        case Operator::NEQ: 
            switch(opType) {
                case Type::INTEGER: return generator->builder.CreateICmpNE(L, R, "ine");
                case Type::FLOAT: return generator->builder.CreateFCmpONE(L, R, "fne");
            }

        case Operator::GT: 
            switch(opType) {
                case Type::INTEGER: return generator->builder.CreateICmpSGT(L, R, "igt");
                case Type::FLOAT: return generator->builder.CreateFCmpOGT(L, R, "fgt");
            }
        
        case Operator::GTE: 
            switch(opType) {
                case Type::INTEGER: return generator->builder.CreateICmpSGE(L, R, "ige");
                case Type::FLOAT: return generator->builder.CreateFCmpOGE(L, R, "fge");
            }
        
        case Operator::LT: 
            switch(opType) {
                case Type::INTEGER: return generator->builder.CreateICmpSLT(L, R, "ilt");
                case Type::FLOAT: return generator->builder.CreateFCmpOLT(L, R, "flt");
            }
        
        case Operator::LTE: 
            switch(opType) {
                case Type::INTEGER: return generator->builder.CreateICmpSLE(L, R, "ile");
                case Type::FLOAT: return generator->builder.CreateFCmpOLE(L, R, "fle");
            }

        case Operator::LOGAND: return generator->builder.CreateLogicalAnd(L, R, "logicand");

        case Operator::LOGOR: return generator->builder.CreateLogicalOr(L, R, "logicor");
    }

    return nullptr;
}

llvm::Value *AssignOpNode::CodeGen(CodeGenerator *generator) {
    llvm::Value *L = leftValue->CodeGen(generator);
    llvm::Value *R = rightValue->CodeGen(generator);

    return generator->builder.CreateStore(R, L);
}

llvm::Value *IdentifierNode::CodeGen(CodeGenerator *generator) {
    //std::string Name = std::string(id);
    //llvm::Value *V = NamedValues[Name];
    //if (!V) return LogErrorV("[ERROR] Unknown Identifier name!");
    //return V;
    return nullptr;
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
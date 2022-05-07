#include "CodeGenerator.h"

//===------------------------------------------------------------===//
// Auxiliary Function
//===------------------------------------------------------------===//

llvm::AllocaInst *CreateEntryBlockAlloca(llvm::Function * TheFunction, llvm::StringRef VarName, llvm::Type *type) {
    llvm::IRBuilder<> Tmp(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    return Tmp.CreateAlloca(type, nullptr, VarName);
}

llvm::Type *TypeNode::ConverToLLVMPtrType(Type type) {
    switch (type)
    {
        case Type::INTEGER: return llvm::Type::getInt32PtrTy(*TheContext);
        case Type::FLOAT: return llvm::Type::getDoublePtrTy(*TheContext);
        case Type::VOID: return llvm::Type::getDoublePtrTy(*TheContext);
        default: Info("[ERROR] Invalid Type!"); return nullptr;
    }
}

llvm::Type *TypeNode::ConvertToLLVMType(Type type) {
    switch (type)
    {
        case Type::INTEGER: return llvm::Type::getInt32Ty(*TheContext);
        case Type::FLOAT: return llvm::Type::getDoubleTy(*TheContext);
        case Type::VOID: return llvm::Type::getVoidTy(*TheContext);
        default: Info("[ERROR] Invalid Type!"); return nullptr;
    }
}

llvm::Constant *TypeNode::initValue(Type type) {
    switch(type) {
        // TO DO : analyze int a = 1 + b * 3; Type::VOID
        case Type::INTEGER: return Builder->getInt32(0);
        case Type::FLOAT: return llvm::ConstantFP::get(Builder->getDoubleTy(), 0.0);
        case Type::VOID: return nullptr;
        default: Info("[ERROR] Invalid Type!"); return nullptr;
    }
}

//===------------------------------------------------------------===//
// Code Generation
//===------------------------------------------------------------===//

llvm::Value *TranslationUnitNode::CodeGen() {
    Info("[NODE] TranslationNode");
    for (auto def : definitions)
        def->CodeGen();
    return nullptr;
}

llvm::Value *FunctionNode::CodeGen() {
    // Make the function type.
    std::vector<Type> paramTypes;
    parameters->GetParameterTypes(paramTypes);
    std::vector<llvm::Type*> Variables;
    for(auto type : paramTypes) {
        Variables.push_back(TypeNode::ConvertToLLVMType(type));
    }
    llvm::FunctionType *FT = llvm::FunctionType::get(TypeNode::ConvertToLLVMType(returnType->GetType()), Variables, false);

    llvm::Function *F = llvm::Function::Create(FT, llvm::Function::ExternalLinkage, name->GetName(), TheModule.get());

    // Set names for all arguments.
    std::vector<std::string> paramNames;
    parameters->GetParameterNames(paramNames);
    unsigned int i = 0;
    for (auto &arg : F->args()) arg.setName(paramNames[i++]);

    // Create a new basic block to start insertion into.
    llvm::BasicBlock *BB = llvm::BasicBlock::Create(*TheContext, "entry", F);
    Builder->SetInsertPoint(BB);

    // Record the function arguments in the NamedValues map.
    NamedValues.clear();
    for (auto &arg : F->args()) NamedValues[std::string(arg.getName())] = &arg;
    
    // Create Function Body
    body->CodeGen();
    
    // Finish off the function.
    //Builder->CreateRet(RetVal);

    // Validate the generated code, checking for consistency.
    verifyFunction(*F);
    return F;

    // Error reading body, remove function.
    //F->eraseFromParent();
    //return nullptr;
}

llvm::Value *ParameterListNode::CodeGen() {
    return nullptr;
}

llvm::Value *DeclarationNode::CodeGen() {
    Info("[NODE] DeclarationNode");
    std::string dname = std::string(name->GetName());

    llvm::Value *res = nullptr;
    
    // if (this->isGlobal) {
        //res = new llvm::GlobalVariable(*TheModule, TypeNode::ConvertToLLVMType(type->GetType()), true,
        //                                llvm::GlobalValue::ExternalLinkage, TypeNode::initValue(type->GetType()), DecName);
        //if (initValue) res = Builder->CreateStore(initValue->CodeGen(), res);
    // }
    // else {
        //res = CreateEntryBlockAlloca(, this->type->toLLVMPtrType);
        res = Builder->CreateAlloca(TypeNode::ConvertToLLVMType(type->GetType()), nullptr, dname);
    // }
    
    return res;
}

llvm::Value *TypeNode::CodeGen() {
    /*
    switch (type)
    {
        case Type::INTEGER: return Builder->getInt32Ty();
        case Type::FLOAT: return Builder->getDoubleTy();
        case Type::VOID: return Builder->getVoidTy();
        default: LogErrorV("[ERROR] Invalid Type!"); return nullptr;
    }
    */
    return nullptr;
}

llvm::Value *IdentifierNode::CodeGen() {
    std::string Name = std::string(id);
    llvm::Value *V = NamedValues[Name];
    if (!V) return LogErrorV("[ERROR] Unknown Identifier name!");
    return V;
}

llvm::Value *CompoundStatementNode::CodeGen() {
    llvm::Value *res = nullptr;
    for (auto item : items)
        item->CodeGen();
    return res;
}

llvm::Value *ExpressionNode::CodeGen() {
    /*
    switch (valueType)
    {
        case Type::INTEGER: return Builder->getInt32Ty();
        case Type::FLOAT: return Builder->getDoubleTy();
        case Type::VOID: return Builder->getVoidTy();
        default: LogErrorV("[ERROR] Invalid Type!"); return nullptr;
    }
    */
    return nullptr;
}

llvm::Value *AssignOpNode::CodeGen() {
    llvm::Value *L = leftValue->CodeGen();
    llvm::Value *R = rightValue->CodeGen();

    return Builder->CreateStore(R, L);
}

llvm::Value *BinaryOpNode::CodeGen() {
    llvm::Value *L = leftOperand->CodeGen();
    llvm::Value *R = rightOperand->CodeGen();

    Type leftType = leftOperand->GetValueType();
    Type rightType = leftOperand->GetValueType();

    Type opType = TypeNode::GetPromotedTypeBetween(leftType, rightType);

    if (!L || !R) 
        return nullptr;

    // TO DO : switch opType to decide the valueType.
    switch(op) {
        case Operator::ADD: 
            switch(opType) {
                case Type::INTEGER: return Builder->CreateAdd(L, R, "iaddtmp");
                case Type::FLOAT: return Builder->CreateFAdd(L, R, "faddtmp");
                case Type::VOID: return Builder->CreateAdd(L, R, "vaddtmp");
            }
        
        case Operator::AND: 
            switch (opType) {
                case Type::INTEGER: return Builder->CreateAnd(L, R, "iandtmp");
                case Type::FLOAT: return Builder->CreateAnd(L, R, "andtmp");
            }
        
        case Operator::DIV: return Builder->CreateFDiv(L, R, "divtmp");
        case Operator::EQ: return Builder->CreateFCmpOEQ(L, R, "eqtmp");
        case Operator::NEQ: return Builder->CreateFCmpONE(L, R, "neqtmp");
        case Operator::GT: return Builder->CreateFCmpUGT(L, R, "gttmp");
        case Operator::GTE: return Builder->CreateFCmpOGE(L, R, "gtetmp");
        case Operator::LOGAND: 
        case Operator::LOGOR: 
        case Operator::LT: L = Builder->CreateFCmpULT(L, R, "cmptmp");
                            return Builder->CreateUIToFP(L, llvm::Type::getDoubleTy(*TheContext), "booltmp");
        case Operator::LTE: return Builder->CreateFCmpOLE(L, R, "ltetmp");
        case Operator::MOD: return nullptr;
        case Operator::MUL: return Builder->CreateFMul(L, R, "multmp");
        case Operator::NOT: return nullptr;
        case Operator::OR:  return Builder->CreateOr(L, R, "ortmp");
        case Operator::SUB: return Builder->CreateFSub(L, R, "subtmp");
        case Operator::XOR: return nullptr;
    }

    return nullptr;
}

llvm::Value *FunctionCallNode::CodeGen() {

    /*
    arguments->CodeGen();
    
    llvm::Function *CalleeF = TheModule->getFunction(std::string(name->GetName()));
    if (!CalleeF)
        return LogErrorV("[ERROR] Unknown Function Referenced!");

    std::vector<llvm::Value *> ArgsV;
    for (unsigned i = 0, e = arguments->arguments.size(); i != e; ++i) {
        ArgsV.push_back(arguments->arguments[i]->CodeGen());
        if (!ArgsV.back())
            return nullptr;
    }

    return Builder->CreateCall(CalleeF, ArgsV, "calltmp");
    */

    return nullptr;

}

llvm::Value *ArgumentListNode::CodeGen() {
    for (auto iter = arguments.begin(); iter != arguments.end(); iter++)
        (*iter)->CodeGen();
    return nullptr;
}

llvm::Value *IntegerNode::CodeGen() {
    return Builder->getInt32(num);
}

llvm::Value *FloatNode::CodeGen() {
    return llvm::ConstantFP::get(Builder->getDoubleTy(), num);
}

llvm::Value *IfStatementNode::CodeGen() {
    condition->CodeGen();
    thenStmt->CodeGen();
    elseStmt->CodeGen();

    return nullptr;
}

llvm::Value *EmptyExpressionNode::CodeGen() {
    return nullptr;
}

llvm::Value *WhileStatementNode::CodeGen() {
    condition->CodeGen();
    body->CodeGen();

    return nullptr;
}

llvm::Value *ForStatementNode::CodeGen() {
    init->CodeGen();
    condition->CodeGen();
    loop->CodeGen();
    body->CodeGen();

    return nullptr;
}

llvm::Value *ReturnStatementNode::CodeGen() {
    exprStmt->CodeGen();

    return nullptr;
}

llvm::Value *ExpressionStatementNode::CodeGen() {
    return expression->CodeGen();
}

//===------------------------------------------------------------===//
// Top-Level Initialize & Generate
//===------------------------------------------------------------===//

void InitializeModule() {
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();

    // Open a new context and module.
    TheContext = std::make_unique<llvm::LLVMContext>();
    TheModule = std::make_unique<llvm::Module>("my cool jit", *TheContext);

    // Create a new builder for the module.
    Builder = std::make_unique<llvm::IRBuilder<>>(*TheContext);
}

void Generate(ASTNode *root) {
    Info("[CODEGEN] IR generation begin...");
    if (root == nullptr) printf("shit\n");
    root->CodeGen();
    Info("[CODEGEN] IR generation finished...");
    TheModule->print(llvm::errs(), nullptr);
}

llvm::Value *LogErrorV(const char *str) {
  fprintf(stderr, "CodeGen Error : %s\n", str);
  return nullptr;
}

void Info(const char *str) {
  fprintf(stdout, "Info : %s\n", str);
}

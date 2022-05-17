#include <assert.h>
#include <stdio.h>
#include <cstring>
#include "FunctionNode.h"
#include "DeclarationNode.h"
#include "StatementNode.h"
#include "ExpressionNode.h"
#include "TypeNode.h"
#include "Utility.h"
#include "SemanticAnalyzer.h"
#include "CodeGenerator.h"

/*      (DE)CONSTRUCT FUNCTION      */

FunctionNode::FunctionNode(TypeNode *returnType, IdentifierNode *name, ParameterListNode *parameters, CompoundStatementNode *body)
	: ASTNode(), returnType(returnType), name(name), parameters(parameters), body(body)
{
	assert(NOT_NULL(returnType));
	assert(NOT_NULL(name));
	assert(NOT_NULL(parameters));
	assert(NOT_NULL(body));
}

FunctionNode::~FunctionNode() {
	delete returnType;
	delete name;
	delete parameters;
	delete body;
}

ParameterListNode::~ParameterListNode() {
	for(auto param : parameters) delete param;
}

/*    (DE)CONSTRUCT FUNCTION END    */

/*         SEMANTIC ANALYZE         */

void FunctionNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {

	/* Check Redeclaration */
	std::string sym(name->GetName());
	if(analyzer->HasSymbol(sym)) {
		throw ASTException("Redeclaration of symbol '" + sym + "'.");
	}

	/* Add Function Definition */
	std::vector<Type> paramTypes;
	for(auto param : parameters->parameters) {
        paramTypes.push_back(param->GetType());
    }
	analyzer->AddSymbol(
		sym,
		SymbolTableEntry(
			SymbolKind::FUNCTION,
			SymbolType(returnType->GetType(), paramTypes)
		)
	);

	/* Create Symbol Table in Function Scope */
	analyzer->EnterFunction(returnType->GetType());
	analyzer->AddNewTable();
	parameters->AnalyzeSemantic(analyzer);

	/* Move into Function Body */
	body->AnalyzeSemantic(analyzer);

	/* Leave Function */
	analyzer->RemoveTable();
	analyzer->LeaveFunction();
}

void ParameterListNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {

	for(auto param : parameters) param->AnalyzeSemantic(analyzer);
	for(auto &it : analyzer->GetCurrentTable()) it.second.kind = SymbolKind::ARGUMENT;
}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void FunctionNode::PrintContentInLevel(int level) const {
	printf("Function Definition\n");

	PRINT_CHILD_WITH_HINT(returnType, "RETURN TYPE");
	PRINT_CHILD_WITH_HINT(name, "NAME");
	PRINT_CHILD_WITH_HINT(parameters, "PARAMS");
	PRINT_CHILD_WITH_HINT(body, "BODY");
}

void ParameterListNode::PrintContentInLevel(int level) const {
	printf("Parameter List\n");

	for(auto param : parameters) {
		PRINT_CHILD_WITH_HINT(param, "PARAM");
	}
}

/*        PRINT FUNCTION END        */

/*         GENERATE IR CODE         */

llvm::Value *FunctionNode::GenerateIR(CodeGenerator *generator) {

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
    llvm::BasicBlock *funcBody = generator->CreateBasicBlock("", function);
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

    /* Jump to Global Initialization if in Function "main" */
    if(strcmp(name->GetName(), ENTRANCE) == 0) {
    	generator->builder.CreateCall(generator->module.getFunction(std::string(GLOBALINIT)));
    }

    /* Generate Function Body */
    body->GenerateIR(generator);

    /* Generate Default Return Instruction */
    generator->builder.CreateRetVoid();

    /* This doesn't work
    if(retType == Type::VOID) {
        generator->builder.CreateRetVoid();
    } else {
        generator->builder.CreateRet(generator->GetTypeDefaultValue(retType));
    }
    */

    /* Finish up */
    generator->JumpToVoid();
    generator->RemoveTable();
    //verifyFunction(*function);
    return function;
}

llvm::Value *ParameterListNode::GenerateIR(CodeGenerator *generator) {
    return nullptr;
}

/*       GENERATE IR CODE END       */

/*        AUXILIARY FUNCTION        */

void ParameterListNode::AppendParameter(DeclarationNode *param) {
	assert(NOT_NULL(param));
	parameters.push_back(param);
}

/*      AUXILIARY FUNCTION END      */
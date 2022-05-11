#include <assert.h>
#include <stdio.h>
#include "FunctionCallNode.h"
#include "ExpressionNode.h"
#include "Utility.h"
#include "SemanticAnalyzer.h"
#include "CodeGenerator.h"

/*      (DE)CONSTRUCT FUNCTION      */

FunctionCallNode::FunctionCallNode(IdentifierNode *name, ArgumentListNode *arguments)
	: ExpressionNode(), name(name), arguments(arguments)
{
	assert(NOT_NULL(name));
	assert(NOT_NULL(arguments));
}

FunctionCallNode::~FunctionCallNode() {
	delete name;
	delete arguments;
}

ArgumentListNode::~ArgumentListNode() {
	for(auto arg : arguments) delete arg;
}

/*    (DE)CONSTRUCT FUNCTION END    */

/*         SEMANTIC ANALYZE         */

void FunctionCallNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {

	name->AnalyzeSemantic(analyzer);
	arguments->AnalyzeSemantic(analyzer);

	/* Start Type Checking */
	char message[128];

	/* Check Symbol Kind */
	char *fname = name->GetName();
	std::string sym(fname);
	const auto &symbolContent = analyzer->FindSymbolOccurrence(sym)->at(sym);
	if(symbolContent.kind != SymbolKind::FUNCTION) {
		sprintf(message, "'%s' is not a function.", fname);
		throw ASTException(message);
	}
	
	/* Get Parameter Types */
	const auto &paramTypes = symbolContent.type.argTypes;
	int paramNum = paramTypes.size();

	/* Get Argument Types*/
	std::vector<Type> argTypes;
	for(auto arg : arguments->arguments) {
		argTypes.push_back(arg->GetValueType());
	}
	int argNum = argTypes.size();

	/* Validate Argument Types */
	if(argNum != paramNum) {
		sprintf(message, "function %s expects %d arguments, %d provided.", fname, paramNum, argNum);
		throw ASTException(message);
	}

	for(int i = 0; i < paramNum; i++) {
		if(!TypeUtils::CanConvert(argTypes[i], paramTypes[i])) {
			sprintf(message, "cannot convert '%s' to '%s' in call to function %s.",
				TypeUtils::GetTypeName(argTypes[i]), TypeUtils::GetTypeName(paramTypes[i]), fname);
			throw ASTException(message);
		}
	}

	/* Determine Value Type */
	valueType = name->GetValueType();
}

void ArgumentListNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {

	for(auto arg : arguments) arg->AnalyzeSemantic(analyzer);
}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void FunctionCallNode::PrintContentInLevel(int level) const {
	printf("Function Call\n");

	PRINT_CHILD_WITH_HINT(name, "NAME");
	PRINT_CHILD_WITH_HINT(arguments, "ARGS");
}

void ArgumentListNode::PrintContentInLevel(int level) const {
	printf("Argument List\n");

	for(auto arg : arguments) {
		PRINT_CHILD_WITH_HINT(arg, "ARG");
	}
}

/*        PRINT FUNCTION END        */

/*         GENERATE IR CODE         */

llvm::Value *FunctionCallNode::GenerateIR(CodeGenerator *generator) {

    llvm::Function *function = generator->module.getFunction(std::string(name->GetName()));

    std::vector<llvm::Value *> args;
    for(auto arg : arguments->arguments) {
        args.push_back(arg->GenerateIR(generator));
    }

    return generator->builder.CreateCall(function, args, "calltmp");
}

llvm::Value *ArgumentListNode::GenerateIR(CodeGenerator *generator) {
    return nullptr;
}

/*       GENERATE IR CODE END       */

/*        AUXILIARY FUNCTION        */

void ArgumentListNode::AppendArgument(ExpressionNode *arg) {
	assert(NOT_NULL(arg));
	arguments.push_back(arg);
}

/*      AUXILIARY FUNCTION END      */
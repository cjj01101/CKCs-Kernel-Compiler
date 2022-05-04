#include <assert.h>
#include <stdio.h>
#include "FunctionNode.h"
#include "ExpressionNode.h"
#include "DeclarationNode.h"
#include "StatementNode.h"

/*      (DE)CONSTRUCT FUNCTION      */

FunctionNode::FunctionNode(IdentifierNode *name, TypeNode *returnType, ParameterListNode *parameters, CompoundStatementNode *body)
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

FunctionCallNode::FunctionCallNode(ASTNode *name, ASTNode *arguments)
	: ExpressionNode(), name(name), arguments(arguments)
{
	assert(NOT_NULL_OF_TYPE(name, IdentifierNode*));
	assert(NOT_NULL_OF_TYPE(arguments, ArgumentListNode*));
}

/*    (DE)CONSTRUCT FUNCTION END    */

/*         SEMANTIC ANALYZE         */

void FunctionNode::AnalyzeSemantic(SymbolTable *intab) {

	std::string sym = std::string(name->GetName());
	if(intab->HasSymbol(sym)) {
		throw ASTException("Redeclaration of symbol '" + sym + "'.");
	}

	/* Add Function Definition */
	std::vector<Type> paramTypes;
	parameters->GetParameterTypes(paramTypes);
	intab->AddEntry(
		sym,
		SymbolTableEntry(
			SymbolKind::function,
			SymbolType(returnType->GetType(), paramTypes)
		)
	);

	/* Create Symbol Table in Function Scope */
	SymbolTable symtab;
	symtab.prev = intab;
	parameters->AnalyzeSemantic(&symtab);

	/* Move into Function Body */
	body->AnalyzeSemantic(&symtab);

}

void ParameterListNode::AnalyzeSemantic(SymbolTable *intab) {

	for(auto param : parameters) param->AnalyzeSemantic(intab);
}

void FunctionCallNode::AnalyzeSemantic(SymbolTable *intab) {

	name->AnalyzeSemantic(intab);
	arguments->AnalyzeSemantic(intab);
}

void ArgumentListNode::AnalyzeSemantic(SymbolTable *intab) {

	for(auto arg : arguments) arg->AnalyzeSemantic(intab);
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

/*        AUXILIARY FUNCTION        */

void ParameterListNode::AppendParameter(DeclarationNode *param) {
	assert(NOT_NULL(param));
	parameters.push_back(param);
}

void ParameterListNode::GetParameterTypes(std::vector<Type> &types) {
	for(auto param : parameters) types.push_back(param->GetType());
}

void ArgumentListNode::AppendArgument(ASTNode *arg) {
	assert(NOT_NULL_OF_TYPE(arg, ExpressionNode*));
	arguments.push_back(arg);
}

/*      AUXILIARY FUNCTION END      */
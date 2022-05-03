#include <stdio.h>
#include "FunctionNode.h"
#include "ExpressionNode.h"
#include "DeclarationNode.h"
#include "StatementNode.h"

/*        CONSTRUCT FUNCTION        */

FunctionNode::FunctionNode(ASTNode *name, ASTNode *returnType, ASTNode *parameters, ASTNode *body)
	: ASTNode(), returnType(returnType), name(name), parameters(parameters), body(body)
{
	assert(NOT_NULL_OF_TYPE(name, IdentifierNode*));
	assert(NOT_NULL_OF_TYPE(returnType, TypeNode*));
	assert(NOT_NULL_OF_TYPE(parameters, ParameterListNode*));
	assert(NOT_NULL_OF_TYPE(body, CompoundStatementNode*));
}

FunctionCallNode::FunctionCallNode(ASTNode *name, ASTNode *arguments)
	: ExpressionNode(), name(name), arguments(arguments)
{
	assert(NOT_NULL_OF_TYPE(name, IdentifierNode*));
	assert(NOT_NULL_OF_TYPE(arguments, ArgumentListNode*));
}

/*      CONSTRUCT FUNCTION END      */

/*         PRINT FUNCTION         */

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

void ParameterListNode::AppendParameter(ASTNode *param) {
	assert(NOT_NULL_OF_TYPE(param, DeclarationNode*));
	parameters.push_back(param);
}

void ArgumentListNode::AppendArgument(ASTNode *arg) {
	assert(NOT_NULL_OF_TYPE(arg, ExpressionNode*));
	arguments.push_back(arg);
}

/*      AUXILIARY FUNCTION END      */
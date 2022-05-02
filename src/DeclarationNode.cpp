#include <stdio.h>
#include "DeclarationNode.h"
#include "ValueNode.h"
#include "StatementNode.h"

/*        CONSTRUCT FUNCTION        */

DeclarationNode::DeclarationNode(ASTNode *name, ASTNode *type, ASTNode *init)
	: ASTNode(), name(name), type(type), initValue(init)
{
	assert(NOT_NULL_OF_TYPE(name, IdentifierNode*));
	assert(NOT_NULL_OF_TYPE(type, TypeNode*));
	assert(NULLABLE_OF_TYPE(init, ExpressionNode*));
}

FunctionNode::FunctionNode(ASTNode *name, ASTNode *returnType, ASTNode *parameters, ASTNode *body)
	: ASTNode(), returnType(returnType), name(name), parameters(parameters), body(body)
{
	assert(NOT_NULL_OF_TYPE(name, IdentifierNode*));
	assert(NOT_NULL_OF_TYPE(returnType, TypeNode*));
	assert(NOT_NULL_OF_TYPE(parameters, ParameterListNode*));
	assert(NOT_NULL_OF_TYPE(body, CompoundStatementNode*));
}

/*      CONSTRUCT FUNCTION END      */

/*         PRINT FUNCTION         */

void DeclarationNode::PrintContentInLevel(int level) const {
	printf("Declaration\n");

	PRINT_CHILD_WITH_HINT(type, "TYPE");
	PRINT_CHILD_WITH_HINT(name, "NAME");
	if(initValue) PRINT_CHILD_WITH_HINT(initValue, "INIT VALUE");
}

void FunctionNode::PrintContentInLevel(int level) const {
	printf("Function Definition\n");

	PRINT_CHILD_WITH_HINT(returnType, "RETURN TYPE");
	PRINT_CHILD_WITH_HINT(name, "NAME");
	PRINT_CHILD_WITH_HINT(parameters, "PARAM");
	PRINT_CHILD_WITH_HINT(body, "BODY");
}

void ParameterListNode::PrintContentInLevel(int level) const {
	printf("Parameter List\n");

	for(auto param : parameters) {
		PRINT_CHILD_WITH_HINT(param, "PARAM");
	}
}

/*        PRINT FUNCTION END        */

/*        AUXILIARY FUNCTION        */

void ParameterListNode::AppendParameter(ASTNode *param) {
	assert(NOT_NULL_OF_TYPE(param, DeclarationNode*));
	parameters.push_back(param);
}

/*      AUXILIARY FUNCTION END      */
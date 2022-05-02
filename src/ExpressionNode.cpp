#include <stdio.h>
#include "ExpressionNode.h"
#include "ValueNode.h"

/*        CONSTRUCT FUNCTION        */

BinaryOpNode::BinaryOpNode(Operator op, ASTNode *left, ASTNode *right)
	: ExpressionNode(), leftOperand(left), rightOperand(right), op(op)
{
	assert(NOT_NULL_OF_TYPE(left, ExpressionNode*));
	assert(NOT_NULL_OF_TYPE(right, ExpressionNode*));
}

AssignOpNode::AssignOpNode(ASTNode *left, ASTNode *right)
	: ExpressionNode(), leftValue(left), rightValue(right)
{ 
	assert(NOT_NULL_OF_TYPE(left, IdentifierNode*));
	assert(NOT_NULL_OF_TYPE(right, ExpressionNode*));
}

FunctionCallNode::FunctionCallNode(ASTNode *name, ASTNode *arguments)
	: ExpressionNode(), name(name), arguments(arguments)
{
	assert(NOT_NULL_OF_TYPE(name, IdentifierNode*));
	assert(NOT_NULL_OF_TYPE(arguments, ArgumentListNode*));
}

/*      CONSTRUCT FUNCTION END      */

/*         PRINT FUNCTION         */

void EmptyExpressionNode::PrintContentInLevel(int level) const {
	printf("Empty Expression\n");
}

void BinaryOpNode::PrintContentInLevel(int level) const {

	const static char *operatorName[] = {
		#define OP(op) #op,
		OPERATORS
		#undef OP
	};

	printf("%s\n", operatorName[static_cast<int>(op)]);

	if(leftOperand) PRINT_CHILD_WITH_HINT(leftOperand, "LEFT");
	if(rightOperand) PRINT_CHILD_WITH_HINT(rightOperand, "RIGHT");

}

void AssignOpNode::PrintContentInLevel(int level) const {
	printf("Assign Expression\n");

	PRINT_CHILD_WITH_HINT(leftValue, "LEFT");
	PRINT_CHILD_WITH_HINT(rightValue, "RIGHT");
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

void ArgumentListNode::AppendArgument(ASTNode *arg) {
	assert(NOT_NULL_OF_TYPE(arg, ExpressionNode*));
	arguments.push_back(arg);
}

/*      AUXILIARY FUNCTION END      */
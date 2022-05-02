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

AssignOpNode::AssignOpNode(ASTNode *left, ASTNode *right) : ExpressionNode(), leftValue(left), rightValue(right)
{ 
	assert(NOT_NULL_OF_TYPE(left, IdentifierNode*));
	assert(NOT_NULL_OF_TYPE(right, ExpressionNode*));
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

/*        PRINT FUNCTION END        */
#include <assert.h>
#include <stdio.h>
#include "OperatorNode.h"
#include "TypeNode.h"

/*        CONSTRUCT FUNCTION        */

BinaryOpNode::BinaryOpNode(Operator op, ExpressionNode *left, ExpressionNode *right)
	: ExpressionNode(), leftOperand(left), rightOperand(right), op(op)
{
	assert(NOT_NULL(left));
	assert(NOT_NULL(right));
}

BinaryOpNode::~BinaryOpNode() {
	delete leftOperand;
	delete rightOperand;
}

AssignOpNode::AssignOpNode(IdentifierNode *left, ExpressionNode *right)
	: ExpressionNode(), leftValue(left), rightValue(right)
{ 
	assert(NOT_NULL(left));
	assert(NOT_NULL(right));
}

AssignOpNode::~AssignOpNode() {
	delete leftValue;
	delete rightValue;
}

/*      CONSTRUCT FUNCTION END      */

/*         SEMANTIC ANALYZE         */

void BinaryOpNode::AnalyzeSemantic(SymbolTable *intab) {

	leftOperand->AnalyzeSemantic(intab);
	rightOperand->AnalyzeSemantic(intab);

	/* Start Type Checking */
	Type leftType = leftOperand->GetValueType();
	Type rightType = rightOperand->GetValueType();

	/* Validate Operand Types */
	if((leftType == Type::VOID || rightType == Type::VOID) ||
	   (IsIntegerOperator() && (leftType != Type::INTEGER || rightType != Type::INTEGER)))
	{
	   	char message[128];
		sprintf(message, "invalid operands of type '%s' and '%s' to binary operator '%s'.",
			TypeNode::GetTypeName(leftType), TypeNode::GetTypeName(rightType), GetOperatorName(op));
		throw ASTException(message);
	}

	/* Determine Value Type */
	valueType = TypeNode::GetPromotedTypeBetween(leftType, rightType);

}

void AssignOpNode::AnalyzeSemantic(SymbolTable *intab) {
	
	leftValue->AnalyzeSemantic(intab);
	rightValue->AnalyzeSemantic(intab);

	/* Start Type Checking */
	Type leftType = leftValue->GetValueType();
	Type rightType = rightValue->GetValueType();

	/* Validate Operand Types */
	if(!TypeNode::IsTypeCompatible(leftType, rightType)) {
		char message[128];
		sprintf(message, "cannot convert '%s' to '%s' in initialization.",
			TypeNode::GetTypeName(leftType), TypeNode::GetTypeName(rightType));
		throw ASTException(message);
	}

	/* Determine Value Type */
	valueType = leftType;

}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void BinaryOpNode::PrintContentInLevel(int level) const {

	printf("%s\n", GetOperatorName(op));

	if(leftOperand) PRINT_CHILD_WITH_HINT(leftOperand, "LEFT");
	if(rightOperand) PRINT_CHILD_WITH_HINT(rightOperand, "RIGHT");

}

void AssignOpNode::PrintContentInLevel(int level) const {
	printf("Assign Expression\n");

	PRINT_CHILD_WITH_HINT(leftValue, "LEFT");
	PRINT_CHILD_WITH_HINT(rightValue, "RIGHT");
}

/*        PRINT FUNCTION END        */

/*        AUXILIARY FUNCTION        */

bool BinaryOpNode::IsIntegerOperator() {
	return (op == Operator::OR || op == Operator::XOR ||
	   		op == Operator::AND || op == Operator::NOT ||
	   		op == Operator::MOD);
}

const char *BinaryOpNode::GetOperatorName(Operator op) {

	const static char *operatorName[] = {
		#define OP(op) #op,
		OPERATORS
		#undef OP
	};

	return operatorName[static_cast<int>(op)];

}

/*      AUXILIARY FUNCTION END      */
#ifndef _OPERATOR_NODE_H_
#define _OPERATOR_NODE_H_

#include "ASTNode.h"

/* Forward Declaration */
class VariableNode;
/* Forward Declaration */

class ArithOpNode : public ASTNode {

public:
	ArithOpNode(char op, ASTNode *left, ASTNode *right) :
		ASTNode(), leftOperand(left), rightOperand(right), op(op) {}
	~ArithOpNode() { delete leftOperand; delete rightOperand; }

private:
	ASTNode *leftOperand;
	ASTNode *rightOperand;
	char op;

	virtual void PrintContentInLevel(int level) const override;

};

class AssignOpNode : public ASTNode {

public:
	AssignOpNode(ASTNode *left, ASTNode *right) : ASTNode(), leftValue(left), rightValue(right)
		{ assert(dynamic_cast<VariableNode*>(left) != nullptr); assert(right != nullptr); }
	~AssignOpNode() { delete leftValue; delete rightValue; }

private:
	ASTNode *leftValue;
	ASTNode *rightValue;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
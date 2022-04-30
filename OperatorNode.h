#ifndef _OPERATOR_NODE_H_
#define _OPERATOR_NODE_H_

#include "ASTNode.h"

class ArithOpNode : public ASTNode {

public:
	ArithOpNode(char op, ASTNode *left, ASTNode *right) :
		ASTNode(), leftOperand(left), rightOperand(right), op(op) {}
	~ArithOpNode() { delete leftOperand; delete rightOperand; }

private:
	ASTNode *leftOperand;
	ASTNode *rightOperand;
	char op;

	virtual void PrintContentInLevel(int level) override;

};

#endif
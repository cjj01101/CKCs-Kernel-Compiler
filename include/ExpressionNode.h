#ifndef _EXPRESSION_NODE_H_
#define _EXPRESSION_NODE_H_

#include "ASTNode.h"

class ExpressionNode : public ASTNode {

public:
	ExpressionNode() : ASTNode() {}
	virtual ~ExpressionNode() {}

protected:


};

class EmptyExpressionNode : public ExpressionNode {

public:
	EmptyExpressionNode() : ExpressionNode() {}
	~EmptyExpressionNode() {}

private:
	virtual void PrintContentInLevel(int level) const override;

};

class BinaryOpNode : public ExpressionNode {

public:
	BinaryOpNode(Operator op, ASTNode *left, ASTNode *right);
	~BinaryOpNode() { delete leftOperand; delete rightOperand; }

private:
	ASTNode *leftOperand;
	ASTNode *rightOperand;
	Operator op;

	virtual void PrintContentInLevel(int level) const override;

};

class AssignOpNode : public ExpressionNode {

public:
	AssignOpNode(ASTNode *left, ASTNode *right);
	~AssignOpNode() { delete leftValue; delete rightValue; }

private:
	ASTNode *leftValue;
	ASTNode *rightValue;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
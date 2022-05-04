#ifndef _OPERATOR_NODE_H_
#define _OPERATOR_NODE_H_

#include "ExpressionNode.h"

class BinaryOpNode : public ExpressionNode {

public:
	BinaryOpNode(Operator op, ASTNode *left, ASTNode *right);
	~BinaryOpNode() { delete leftOperand; delete rightOperand; }

	virtual void AnalyzeSemantic(SymbolTable *intab) override;

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

	virtual void AnalyzeSemantic(SymbolTable *intab) override;

private:
	ASTNode *leftValue;
	ASTNode *rightValue;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
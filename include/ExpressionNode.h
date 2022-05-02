#ifndef _EXPRESSION_NODE_H_
#define _EXPRESSION_NODE_H_

#include <vector>
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

class FunctionCallNode : public ExpressionNode {

public:
	FunctionCallNode(ASTNode *name, ASTNode *arguments);
	~FunctionCallNode() { delete name; delete arguments; }

private:
	ASTNode *name;
	ASTNode *arguments;

	virtual void PrintContentInLevel(int level) const override;

};

class ArgumentListNode : public ASTNode {

public:
	ArgumentListNode() : ASTNode(), arguments() {}
	~ArgumentListNode() {
		for(auto arg : arguments) delete arg;
	}

	void AppendArgument(ASTNode *arg);

private:
	std::vector<ASTNode*> arguments;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
#ifndef _VALUE_NODE_H_
#define _VALUE_NODE_H_

#include "ExpressionNode.h"

class IntegerNode : public ExpressionNode {

public:
	IntegerNode(int num) : ExpressionNode(), num(num) {}
	~IntegerNode() {}

private:
	int num;

	virtual void PrintContentInLevel(int level) const override;

};

class IdentifierNode : public ExpressionNode {

public:
	IdentifierNode(char *name);
	~IdentifierNode() {}

private:
	char id[MAXVARLEN];

	virtual void PrintContentInLevel(int level) const override;

};

class TypeNode : public ASTNode {

public:
	TypeNode(Type type) : ASTNode(), type(type) { }
	~TypeNode() {}

private:
	Type type;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
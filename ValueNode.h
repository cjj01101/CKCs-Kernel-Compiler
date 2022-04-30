#ifndef _VALUE_NODE_H_
#define _VALUE_NODE_H_

#include "ASTNode.h"

class IntegerNode : public ASTNode {

public:
	IntegerNode(int num) : ASTNode(), num(num) {}
	~IntegerNode() {}

private:
	int num;

	virtual void PrintContentInLevel(int level) const override;

};

class VariableNode : public ASTNode {

public:
	VariableNode(char *name);
	~VariableNode() {}

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
#ifndef _VALUE_NODE_H_
#define _VALUE_NODE_H_

#include "ASTNode.h"
#include "common.h"

class IntegerNode : public ASTNode {

public:
	IntegerNode(int num) : ASTNode(), num(num) {}
	~IntegerNode() {}

private:
	int num;

	virtual void PrintContentInLevel(int level) override;

};

class VariableNode : public ASTNode {

public:
	VariableNode(char *name);
	~VariableNode() {}

private:
	char id[MAXVARLEN];

	virtual void PrintContentInLevel(int level) override;

};

#endif
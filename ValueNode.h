#ifndef _VALUE_NODE_H_
#define _VALUE_NODE_H_

#include "ASTNode.h"

class IntegerNode : public ASTNode {

public:
	IntegerNode(int num) : ASTNode(), num(num) {}
	~IntegerNode() {}

private:
	int num;

	virtual void PrintContentInLevel(int level) override { cout << num << endl; }

};

#endif
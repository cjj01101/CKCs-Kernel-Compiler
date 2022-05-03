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

class FloatNode : public ExpressionNode {

public:
	FloatNode(float num) : ExpressionNode(), num(num) {}
	~FloatNode() {}

private:
	float num;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
#ifndef _CONSTANT_NODE_H_
#define _CONSTANT_NODE_H_

#include "ExpressionNode.h"

class ConstantNode : public ExpressionNode {

public:
	ConstantNode() : ExpressionNode() {}
	virtual ~ConstantNode() {}

	virtual void AnalyzeSemantic(SymbolTable *intab) override;

protected:

};

class IntegerNode : public ConstantNode {

public:
	IntegerNode(int num) : ConstantNode(), num(num) {}
	~IntegerNode() {}

private:
	int num;

	virtual void PrintContentInLevel(int level) const override;

};

class FloatNode : public ConstantNode {

public:
	FloatNode(float num) : ConstantNode(), num(num) {}
	~FloatNode() {}

private:
	float num;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
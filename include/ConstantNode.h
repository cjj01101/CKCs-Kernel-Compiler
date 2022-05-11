#ifndef _CONSTANT_NODE_H_
#define _CONSTANT_NODE_H_

#include "ExpressionNode.h"

class ConstantNode : public ExpressionNode {

public:
	ConstantNode(Type type) : ExpressionNode() { valueType = type; }
	virtual ~ConstantNode() {}

	virtual void AnalyzeSemantic(SemanticAnalyzer *analyzer) override;

protected:

};

class IntegerNode : public ConstantNode {

public:
	IntegerNode(int num) : ConstantNode(Type::INTEGER), num(num) { }
	~IntegerNode() {}

	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;

private:
	int num;

	virtual void PrintContentInLevel(int level) const override;

};

class FloatNode : public ConstantNode {

public:
	FloatNode(float num) : ConstantNode(Type::FLOAT), num(num) {}
	~FloatNode() {}

	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;

private:
	float num;

	virtual void PrintContentInLevel(int level) const override;

};

class BooleanNode : public ConstantNode {

public:
	BooleanNode(bool num) : ConstantNode(Type::BOOLEAN), num(num) {}
	~BooleanNode() {}
	
	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;

private:
	bool num;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
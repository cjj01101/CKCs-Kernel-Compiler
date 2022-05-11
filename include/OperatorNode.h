#ifndef _OPERATOR_NODE_H_
#define _OPERATOR_NODE_H_

#include "ExpressionNode.h"

class BinaryOpNode : public ExpressionNode {

public:
	BinaryOpNode(Operator op, ExpressionNode *left, ExpressionNode *right);
	~BinaryOpNode();

	bool IsArithmeticOperator();
	bool IsIntegerOperator();
	bool IsLogicalOperator();
	bool IsRelationalOperator();
	bool IsCommaOperator();

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;
	
	static const char *GetOperatorName(Operator op);

private:
	ExpressionNode *leftOperand;
	ExpressionNode *rightOperand;
	Operator op;

	virtual void PrintContentInLevel(int level) const override;

};

class AssignOpNode : public ExpressionNode {

public:
	AssignOpNode(IdentifierNode *left, ExpressionNode *right);
	~AssignOpNode();

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;
	
private:
	IdentifierNode *leftValue;
	ExpressionNode *rightValue;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
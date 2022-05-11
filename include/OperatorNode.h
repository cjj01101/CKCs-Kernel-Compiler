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

	virtual void AnalyzeSemantic(SemanticAnalyzer *analyzer) override;
	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;

private:
	ExpressionNode *leftOperand;
	ExpressionNode *rightOperand;
	Operator op;

	virtual void PrintContentInLevel(int level) const override;

};

class TernaryOpNode : public ExpressionNode {

public:
	TernaryOpNode(ExpressionNode *cond, ExpressionNode *trueExpr, ExpressionNode *falseExpr);
	~TernaryOpNode();

	virtual void AnalyzeSemantic(SemanticAnalyzer *analyzer) override;
	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;

private:
	ExpressionNode *condition;
	ExpressionNode *trueExpression;
	ExpressionNode *falseExpression;

	virtual void PrintContentInLevel(int level) const override;

};

class AssignOpNode : public ExpressionNode {

public:
	AssignOpNode(IdentifierNode *left, ExpressionNode *right);
	~AssignOpNode();

	virtual void AnalyzeSemantic(SemanticAnalyzer *analyzer) override;
	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;
	
private:
	IdentifierNode *leftValue;
	ExpressionNode *rightValue;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
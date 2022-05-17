#ifndef _FUNCTION_CALL_NODE_H_
#define _FUNCTION_CALL_NODE_H_

#include "ExpressionNode.h"

class FunctionCallNode : public ExpressionNode {

public:
	FunctionCallNode(IdentifierNode *name, ArgumentListNode *arguments);
	~FunctionCallNode();

	virtual void AnalyzeSemantic(SemanticAnalyzer *analyzer) override;
	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;

private:
	IdentifierNode *name;
	ArgumentListNode *arguments;

	virtual void PrintContentInLevel(int level) const override;

};

class ArgumentListNode : public ASTNode {

	friend class FunctionCallNode;

public:
	ArgumentListNode() : ASTNode(), arguments() {}
	~ArgumentListNode();

	void AppendArgument(ExpressionNode *arg);

	virtual void AnalyzeSemantic(SemanticAnalyzer *analyzer) override;
	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;
	
private:
	std::vector<ExpressionNode*> arguments;

	virtual void PrintContentInLevel(int level) const override;

};

class PutiCallNode : public ExpressionNode {

public:
	PutiCallNode(ExpressionNode *num);
	~PutiCallNode();

	virtual void AnalyzeSemantic(SemanticAnalyzer *analyzer) override;
	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;

private:
	ExpressionNode *num;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
#ifndef _FUNCTION_NODE_H_
#define _FUNCTION_NODE_H_

#include <string>
#include <vector>
#include "ExpressionNode.h"

class FunctionNode : public ASTNode {

public:
	FunctionNode(IdentifierNode *name, TypeNode *returnType, ParameterListNode *parameters, CompoundStatementNode *body);
	~FunctionNode();

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen(CodeGenerator *generator) override;
	
private:
	TypeNode *returnType;
	IdentifierNode *name;
	ParameterListNode *parameters;
	CompoundStatementNode *body;

	virtual void PrintContentInLevel(int level) const override;

};

class ParameterListNode : public ASTNode {

	friend class FunctionNode;

public:
	ParameterListNode() : ASTNode(), parameters() {}
	~ParameterListNode();

	void AppendParameter(DeclarationNode *param);

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen(CodeGenerator *generator) override;

private:
	std::vector<DeclarationNode*> parameters;

	virtual void PrintContentInLevel(int level) const override;

};

class FunctionCallNode : public ExpressionNode {

public:
	FunctionCallNode(IdentifierNode *name, ArgumentListNode *arguments);
	~FunctionCallNode();

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen(CodeGenerator *generator) override;

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

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen(CodeGenerator *generator) override;
	
private:
	std::vector<ExpressionNode*> arguments;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
#ifndef _FUNCTION_NODE_H_
#define _FUNCTION_NODE_H_

#include <vector>
#include "ExpressionNode.h"

class FunctionNode : public ASTNode {

public:
	FunctionNode(IdentifierNode *name, TypeNode *returnType, ParameterListNode *parameters, CompoundStatementNode *body);
	~FunctionNode();

	virtual void AnalyzeSemantic(SymbolTable *intab) override;

private:
	TypeNode *returnType;
	IdentifierNode *name;
	ParameterListNode *parameters;
	CompoundStatementNode *body;

	virtual void PrintContentInLevel(int level) const override;

};

class ParameterListNode : public ASTNode {

public:
	ParameterListNode() : ASTNode(), parameters() {}
	~ParameterListNode();

	void AppendParameter(DeclarationNode *param);
	void GetParameterTypes(std::vector<Type> &types);

	virtual void AnalyzeSemantic(SymbolTable *intab) override;

private:
	std::vector<DeclarationNode*> parameters;

	virtual void PrintContentInLevel(int level) const override;

};

class FunctionCallNode : public ExpressionNode {

public:
	FunctionCallNode(ASTNode *name, ASTNode *arguments);
	~FunctionCallNode() { delete name; delete arguments; }

	virtual void AnalyzeSemantic(SymbolTable *intab) override;

private:
	ASTNode *name;
	ASTNode *arguments;

	virtual void PrintContentInLevel(int level) const override;

};

class ArgumentListNode : public ASTNode {

public:
	ArgumentListNode() : ASTNode(), arguments() {}
	~ArgumentListNode() {
		for(auto arg : arguments) delete arg;
	}

	void AppendArgument(ASTNode *arg);

	virtual void AnalyzeSemantic(SymbolTable *intab) override;

private:
	std::vector<ASTNode*> arguments;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
#ifndef _FUNCTION_NODE_H_
#define _FUNCTION_NODE_H_

#include <vector>
#include "ExpressionNode.h"

class FunctionNode : public ASTNode {

public:
	FunctionNode(ASTNode *name, ASTNode *returnType, ASTNode *parameters, ASTNode *body);
	~FunctionNode() { delete returnType; delete name; delete parameters; delete body; }

private:
	ASTNode *returnType;
	ASTNode *name;
	ASTNode *parameters;
	ASTNode *body;

	virtual void PrintContentInLevel(int level) const override;

};

class ParameterListNode : public ASTNode {

public:
	ParameterListNode() : ASTNode(), parameters() {}
	~ParameterListNode() {
		for(auto param : parameters) delete param;
	}

	void AppendParameter(ASTNode *param);

private:
	std::vector<ASTNode*> parameters;

	virtual void PrintContentInLevel(int level) const override;

};

class FunctionCallNode : public ExpressionNode {

public:
	FunctionCallNode(ASTNode *name, ASTNode *arguments);
	~FunctionCallNode() { delete name; delete arguments; }

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

private:
	std::vector<ASTNode*> arguments;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
#ifndef _DECLARATION_NODE_H_
#define _DECLARATION_NODE_H_

#include <vector>
#include "ASTNode.h"

class DeclarationNode : public ASTNode {

public:
	DeclarationNode(ASTNode *name, ASTNode *type, ASTNode *init = nullptr);
	~DeclarationNode() { delete type; delete name; delete initValue; }

private:
	ASTNode *type;
	ASTNode *name;
	ASTNode *initValue;

	virtual void PrintContentInLevel(int level) const override;

};

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

#endif
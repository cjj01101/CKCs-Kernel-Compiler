#ifndef _DECLARATION_NODE_H_
#define _DECLARATION_NODE_H_

#include "ASTNode.h"

typedef struct {
    ASTNode *type;
    ASTNode *name;
} Declarator;

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

class TypeNode : public ASTNode {

public:
	TypeNode(Type type) : ASTNode(), type(type) { }
	~TypeNode() {}

private:
	Type type;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
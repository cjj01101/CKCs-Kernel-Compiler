#ifndef _DECLARATION_NODE_H_
#define _DECLARATION_NODE_H_

#include "ASTNode.h"

typedef struct {
    TypeNode *type;
    IdentifierNode *name;
} Declarator;

class TypeNode : public ASTNode {

public:
	TypeNode(Type type) : ASTNode(), type(type) { }
	~TypeNode() {}

	Type GetType() { return type; }

private:
	Type type;

	virtual void PrintContentInLevel(int level) const override;

};

class DeclarationNode : public ASTNode {

public:
	DeclarationNode(IdentifierNode *name, TypeNode *type, ASTNode *init = nullptr);
	~DeclarationNode();

	Type GetType() { return type->GetType(); }

	virtual void AnalyzeSemantic(SymbolTable *intab) override;

private:
	TypeNode *type;
	IdentifierNode *name;
	ASTNode *initValue;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
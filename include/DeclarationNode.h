#ifndef _DECLARATION_NODE_H_
#define _DECLARATION_NODE_H_

#include <vector>
#include "ASTNode.h"

struct Declarator {
	IdentifierNode *name;
	ExpressionNode *initValue;
};

class DeclarationNode : public ASTNode {

public:
	DeclarationNode(TypeNode *type, DeclaratorListNode *declarators);
	~DeclarationNode();

	Type GetType();
	char *GetName();

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;
	
private:
	TypeNode *type;
	DeclaratorListNode *declarators;

	virtual void PrintContentInLevel(int level) const override;

};

class DeclaratorListNode : public ASTNode {

	friend class DeclarationNode;

public:
	DeclaratorListNode() : ASTNode(), declarators() {}
	~DeclaratorListNode() {}

	void AppendDeclarator(const Declarator &declarator);

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;

private:
	std::vector<Declarator> declarators;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
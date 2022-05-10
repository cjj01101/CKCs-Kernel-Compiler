#ifndef _DECLARATION_NODE_H_
#define _DECLARATION_NODE_H_

#include "ASTNode.h"

typedef struct {
    TypeNode *type;
    IdentifierNode *name;
} Declarator;

class DeclarationNode : public ASTNode {

public:
	DeclarationNode(IdentifierNode *name, TypeNode *type, ExpressionNode *init = nullptr);
	~DeclarationNode();

	Type GetType();
	char *GetName();

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;
	
private:
	TypeNode *type;
	IdentifierNode *name;
	ExpressionNode *initValue;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
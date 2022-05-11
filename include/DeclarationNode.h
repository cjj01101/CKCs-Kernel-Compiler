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
	DeclarationNode(TypeNode *type, IdentifierNode *name, ExpressionNode *init = nullptr);
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
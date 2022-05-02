#ifndef _DECLARATION_NODE_H_
#define _DECLARATION_NODE_H_

#include "ASTNode.h"

class DeclarationNode : public ASTNode {

public:
	DeclarationNode(ASTNode *var, ASTNode *type, ASTNode *init = nullptr);
	~DeclarationNode() { delete type; delete variable; delete initValue; }

private:
	ASTNode *type;
	ASTNode *variable;
	ASTNode *initValue;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
#ifndef _DECLARATION_NODE_H_
#define _DECLARATION_NODE_H_

#include "ASTNode.h"

class DeclarationNode : public ASTNode {

public:
	DeclarationNode(ASTNode *var, ASTNode *type) : ASTNode(), variable(var), type(type) {
		assert(dynamic_cast<VariableNode*>(var) != nullptr);
		assert(dynamic_cast<TypeNode*>(type) != nullptr);
	}
	~DeclarationNode() { delete type; delete variable; }

private:
	ASTNode *type;
	ASTNode *variable;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
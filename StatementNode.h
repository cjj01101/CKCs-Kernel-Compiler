#ifndef _STATEMENT_NODE_H_
#define _STATEMENT_NODE_H_

#include "ASTNode.h"

/* Forward Declaration */
class VariableNode;
/* Forward Declaration */

class StatementNode : public ASTNode {

public:
	StatementNode() : ASTNode() {}
	virtual ~StatementNode() {}

protected:

};

class ExpressionStatementNode : public StatementNode {

public:
	ExpressionStatementNode(ASTNode *exp) : StatementNode(), expression(exp)
		{ assert(exp != nullptr); }
	~ExpressionStatementNode() { delete expression; }

private:
	ASTNode *expression;

	virtual void PrintContentInLevel(int level) const override;

};

class DeclarationNode : public StatementNode {

public:
	DeclarationNode(ASTNode *var, ASTNode *type) : StatementNode(), variable(var), type(type) {
		assert(dynamic_cast<VariableNode*>(var) != nullptr);
		assert(dynamic_cast<TypeNode*>(type) != nullptr);
	}
	~DeclarationNode() {}

private:
	ASTNode *type;
	ASTNode *variable;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
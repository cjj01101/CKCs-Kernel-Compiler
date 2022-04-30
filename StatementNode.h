#ifndef _STATEMENT_NODE_H_
#define _STATEMENT_NODE_H_

#include "ASTNode.h"

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

	virtual void PrintContentInLevel(int level) override;

};

#endif
#ifndef _EXPRESSION_NODE_H_
#define _EXPRESSION_NODE_H_

#include <vector>
#include "ASTNode.h"

class ExpressionNode : public ASTNode {

public:
	ExpressionNode() : ASTNode() {}
	virtual ~ExpressionNode() {}

protected:


};

class EmptyExpressionNode : public ExpressionNode {

public:
	EmptyExpressionNode() : ExpressionNode() {}
	~EmptyExpressionNode() {}

private:
	virtual void PrintContentInLevel(int level) const override;

};

class IdentifierNode : public ExpressionNode {

public:
	IdentifierNode(char *name);
	~IdentifierNode() {}

	char *GetName() { return id; }

private:
	char id[MAXVARLEN];

	virtual void PrintContentInLevel(int level) const override;

};

#endif
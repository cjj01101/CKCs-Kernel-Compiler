#ifndef _STATEMENT_NODE_H_
#define _STATEMENT_NODE_H_

#include <vector>
#include "ASTNode.h"

class StatementNode : public ASTNode {

public:
	StatementNode() : ASTNode() {}
	virtual ~StatementNode() {}

protected:

};

class CompoundStatementNode : public StatementNode {

public:
	CompoundStatementNode() : StatementNode(), items() {}
	~CompoundStatementNode() {
		for(auto item : items) delete item;
	}

	void AppendStatement(ASTNode *item);

private:
	std::vector<ASTNode*> items;

	virtual void PrintContentInLevel(int level) const override;

};

class ExpressionStatementNode : public StatementNode {

public:
	ExpressionStatementNode(ASTNode *exp = nullptr);
	~ExpressionStatementNode() { delete expression; }

private:
	ASTNode *expression;

	virtual void PrintContentInLevel(int level) const override;

};

class IfStatementNode : public StatementNode {

public:
	IfStatementNode(ASTNode *condition, ASTNode *thenStmt, ASTNode *elseStmt);
	~IfStatementNode() { delete condition; delete thenStmt; delete thenStmt; }	

private:
	ASTNode *condition;
	ASTNode *thenStmt;
	ASTNode *elseStmt;

	virtual void PrintContentInLevel(int level) const override;

};

class WhileStatementNode : public StatementNode {

public:
	WhileStatementNode(ASTNode *condition, ASTNode *body);
	~WhileStatementNode() { delete condition; delete body; }

private:
	ASTNode *condition;
	ASTNode *body;

	virtual void PrintContentInLevel(int level) const override;

};

class ForStatementNode : public StatementNode {

public:
	ForStatementNode(ASTNode *init, ASTNode *cond, ASTNode *loop, ASTNode *body);
	~ForStatementNode() { delete init; delete condition; delete loop; delete body; }

private:
	ASTNode *init;
	ASTNode *condition;
	ASTNode *loop;
	ASTNode *body;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
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

class EmptyStatementNode : public StatementNode {

public:
	EmptyStatementNode() : StatementNode() {}
	~EmptyStatementNode() {}	

private:
	virtual void PrintContentInLevel(int level) const override;

};

class CompoundStatementNode : public StatementNode {

public:
	CompoundStatementNode() : StatementNode(), statements() {}
	~CompoundStatementNode() {
		for(auto stmt : statements) delete stmt;
	}

	void AppendStatement(ASTNode *stmt) {
		//assert(dynamic_cast<StatementNode*>(stmt) != nullptr);
		statements.push_back(stmt);
	}

private:
	std::vector<ASTNode*> statements;

	virtual void PrintContentInLevel(int level) const override;

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

class IfStatementNode : public StatementNode {

public:
	IfStatementNode(ASTNode *condition, ASTNode *thenStmt, ASTNode *elseStmt) :
		StatementNode(), condition(condition), thenStmt(thenStmt), elseStmt(elseStmt)
	{
		assert(dynamic_cast<StatementNode*>(thenStmt) != nullptr);
		assert(dynamic_cast<StatementNode*>(elseStmt) != nullptr);
	}
	~IfStatementNode() { delete condition; delete thenStmt; delete thenStmt; }	

private:
	ASTNode *condition;
	ASTNode *thenStmt;
	ASTNode *elseStmt;

	virtual void PrintContentInLevel(int level) const override;

};

class WhileStatementNode : public StatementNode {

public:
	WhileStatementNode(ASTNode *condition, ASTNode *body) :
		StatementNode(), condition(condition), body(body)
	{
		assert(dynamic_cast<StatementNode*>(body) != nullptr);
	}
	~WhileStatementNode() { delete condition; delete body; }

private:
	ASTNode *condition;
	ASTNode *body;

	virtual void PrintContentInLevel(int level) const override;

};

class ForStatementNode : public StatementNode {

public:
	ForStatementNode(ASTNode *init, ASTNode *cond, ASTNode *loop, ASTNode *body) :
		StatementNode(), init(init), condition(cond), loop(loop), body(body)
	{
		assert(dynamic_cast<StatementNode*>(init) != nullptr);
		assert(dynamic_cast<StatementNode*>(cond) != nullptr);
		assert(dynamic_cast<StatementNode*>(body) != nullptr);
	}
	~ForStatementNode() { delete init; delete condition; delete loop; delete body; }

private:
	ASTNode *init;
	ASTNode *condition;
	ASTNode *loop;
	ASTNode *body;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
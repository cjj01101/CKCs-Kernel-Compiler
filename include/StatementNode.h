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

class ExpressionStatementNode : public StatementNode {

public:
	ExpressionStatementNode(ExpressionNode *exp);
	~ExpressionStatementNode();

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen() override;
	
private:
	ExpressionNode *expression;

	virtual void PrintContentInLevel(int level) const override;

};

class CompoundStatementNode : public StatementNode {

public:
	CompoundStatementNode() : StatementNode(), items() {}
	~CompoundStatementNode() {
		for(auto item : items) delete item;
	}

	void AppendStatement(ASTNode *item);

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen() override;
	
private:
	std::vector<ASTNode*> items;

	virtual void PrintContentInLevel(int level) const override;

};

class IfStatementNode : public StatementNode {

public:
	IfStatementNode(ExpressionNode *condition, StatementNode *thenStmt, StatementNode *elseStmt);
	~IfStatementNode();

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen() override;
	
private:
	ExpressionNode *condition;
	ASTNode *thenStmt;
	ASTNode *elseStmt;

	virtual void PrintContentInLevel(int level) const override;

};

class WhileStatementNode : public StatementNode {

public:
	WhileStatementNode(ExpressionNode *condition, StatementNode *body);
	~WhileStatementNode();

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen() override;

private:
	ExpressionNode *condition;
	ASTNode *body;

	virtual void PrintContentInLevel(int level) const override;

};

class ForStatementNode : public StatementNode {

public:
	ForStatementNode(ASTNode *init, ExpressionNode *cond, ExpressionNode *loop, StatementNode *body);
	~ForStatementNode();

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen() override;

private:
	ASTNode *init;
	ExpressionNode *condition;
	ExpressionNode *loop;
	ASTNode *body;

	virtual void PrintContentInLevel(int level) const override;

};

class ReturnStatementNode : public StatementNode {

public:
	ReturnStatementNode(ASTNode *exprStmt);
	~ReturnStatementNode() { delete exprStmt; }

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen() override;
	
private:
	ASTNode *exprStmt;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
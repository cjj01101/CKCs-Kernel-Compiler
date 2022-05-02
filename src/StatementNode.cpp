#include <stdio.h>
#include "ExpressionNode.h"
#include "DeclarationNode.h"
#include "StatementNode.h"

/*        CONSTRUCT FUNCTION        */

ExpressionStatementNode::ExpressionStatementNode(ASTNode *exp)
	: StatementNode(), expression(exp)
{
	assert(NULLABLE_OF_TYPE(exp, ExpressionNode*));
}

IfStatementNode::IfStatementNode(ASTNode *condition, ASTNode *thenStmt, ASTNode *elseStmt)
	: StatementNode(), condition(condition), thenStmt(thenStmt), elseStmt(elseStmt)
{
	assert(NOT_NULL_OF_TYPE(condition, ExpressionNode*));
	assert(NOT_NULL_OF_TYPE(thenStmt, StatementNode*));
	assert(NOT_NULL_OF_TYPE(elseStmt, StatementNode*));
}

WhileStatementNode::WhileStatementNode(ASTNode *condition, ASTNode *body)
	: StatementNode(), condition(condition), body(body)
{
	assert(NOT_NULL_OF_TYPE(condition, ExpressionNode*));
	assert(NOT_NULL_OF_TYPE(body, StatementNode*));
}

ForStatementNode::ForStatementNode(ASTNode *init, ASTNode *cond, ASTNode *loop, ASTNode *body)
	: StatementNode(), init(init), condition(cond), loop(loop), body(body)
{
	assert(NOT_NULL_OF_TYPE(init, ExpressionStatementNode*) || 
		   NOT_NULL_OF_TYPE(init, DeclarationNode*));
	assert(NOT_NULL_OF_TYPE(cond, ExpressionStatementNode*));
	assert(NOT_NULL_OF_TYPE(loop, ExpressionNode*));
	assert(NOT_NULL_OF_TYPE(body, StatementNode*));
}

/*      CONSTRUCT FUNCTION END      */

/*         PRINT FUNCTION         */

void CompoundStatementNode::PrintContentInLevel(int level) const {
	printf("Compound Statement\n");

	for(auto item : items) {
		PRINT_CHILD_WITH_HINT(item, "ITEM");
	}
}

void ExpressionStatementNode::PrintContentInLevel(int level) const {
	if(expression == nullptr) {
		printf("Empty Statement\n");
	} else {
		printf("Expression Statement\n");

		PRINT_CHILD_WITH_HINT(expression, "EXPR");
	}
}

void IfStatementNode::PrintContentInLevel(int level) const {
	printf("If Statement\n");

	PRINT_CHILD_WITH_HINT(condition, "COND");
	PRINT_CHILD_WITH_HINT(thenStmt, "THEN");
	PRINT_CHILD_WITH_HINT(elseStmt, "ELSE");
}

void WhileStatementNode::PrintContentInLevel(int level) const {
	printf("While Statement\n");

	PRINT_CHILD_WITH_HINT(condition, "WHILE");
	PRINT_CHILD_WITH_HINT(body, "THEN");
}

void ForStatementNode::PrintContentInLevel(int level) const {
	printf("For Statement\n");

	PRINT_CHILD_WITH_HINT(init, "INIT");
	PRINT_CHILD_WITH_HINT(condition, "COND");
	PRINT_CHILD_WITH_HINT(loop, "END OF LOOP");
	PRINT_CHILD_WITH_HINT(body, "BODY");
}

/*        PRINT FUNCTION END        */

/*        AUXILIARY FUNCTION        */

void CompoundStatementNode::AppendStatement(ASTNode *item) {
	assert(dynamic_cast<StatementNode*>(item) != nullptr ||
		   dynamic_cast<DeclarationNode*>(item) != nullptr);
	items.push_back(item);
}

/*      AUXILIARY FUNCTION END      */
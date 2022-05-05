#include <assert.h>
#include <stdio.h>
#include "ExpressionNode.h"
#include "DeclarationNode.h"
#include "StatementNode.h"
#include "TypeNode.h"

/*      (DE)CONSTRUCT FUNCTION      */

ExpressionStatementNode::ExpressionStatementNode(ExpressionNode *exp)
	: StatementNode(), expression(exp)
{
	assert(NOT_NULL(exp));
}

ExpressionStatementNode::~ExpressionStatementNode() {
	delete expression;
}

IfStatementNode::IfStatementNode(ExpressionNode *condition, StatementNode *thenStmt, StatementNode *elseStmt)
	: StatementNode(), condition(condition), thenStmt(thenStmt), elseStmt(elseStmt)
{
	assert(NOT_NULL(condition));
	assert(NOT_NULL(thenStmt));
	assert(NOT_NULL(elseStmt));
}

IfStatementNode::~IfStatementNode() {
	delete condition;
	delete thenStmt;
	delete thenStmt;
}

WhileStatementNode::WhileStatementNode(ExpressionNode *condition, StatementNode *body)
	: StatementNode(), condition(condition), body(body)
{
	assert(NOT_NULL(condition));
	assert(NOT_NULL(body));
}

WhileStatementNode::~WhileStatementNode() {
	delete condition;
	delete body;
}

ForStatementNode::ForStatementNode(ASTNode *init, ExpressionNode *cond, ExpressionNode *loop, StatementNode *body)
	: StatementNode(), init(init), condition(cond), loop(loop), body(body)
{
	assert(NOT_NULL_OF_TYPE(init, ExpressionStatementNode*) || 
		   NOT_NULL_OF_TYPE(init, DeclarationNode*));
	assert(NOT_NULL(cond));
	assert(NOT_NULL(loop));
	assert(NOT_NULL(body));
}

ForStatementNode::~ForStatementNode() {
	delete init;
	delete condition;
	delete loop;
	delete body;
}

ReturnStatementNode::ReturnStatementNode(ASTNode *exprStmt)
	: StatementNode(), exprStmt(exprStmt)
{
	assert(NOT_NULL_OF_TYPE(exprStmt, ExpressionStatementNode*));
}

/*    (DE)CONSTRUCT FUNCTION END    */

/*         SEMANTIC ANALYZE         */

void ExpressionStatementNode::AnalyzeSemantic(SymbolTable *intab) {
	
	expression->AnalyzeSemantic(intab);
}

void CompoundStatementNode::AnalyzeSemantic(SymbolTable *intab) {
	
	SymbolTable symtab;
	symtab.prev = intab;
	for(auto item : items) item->AnalyzeSemantic(&symtab);

}

void IfStatementNode::AnalyzeSemantic(SymbolTable *intab) {
	
	condition->AnalyzeSemantic(intab);
	thenStmt->AnalyzeSemantic(intab);
	elseStmt->AnalyzeSemantic(intab);

	/* Validate Condition Expression Type */
	Type condType = condition->GetValueType();
	if(!TypeNode::IsTypeCompatible(condType, Type::INTEGER)) {
		throw ASTException("cannot convert '" + std::string(TypeNode::GetTypeName(condType)) + "' to 'BOOL'.");
	}

}

void WhileStatementNode::AnalyzeSemantic(SymbolTable *intab) {
	
	condition->AnalyzeSemantic(intab);
	body->AnalyzeSemantic(intab);

	/* Validate Condition Expression Type */
	Type condType = condition->GetValueType();
	if(!TypeNode::IsTypeCompatible(condType, Type::INTEGER)) {
		throw ASTException("cannot convert '" + std::string(TypeNode::GetTypeName(condType)) + "' to 'BOOL'.");
	}

}

void ForStatementNode::AnalyzeSemantic(SymbolTable *intab) {
	
	SymbolTable symtab;
	symtab.prev = intab;

	init->AnalyzeSemantic(&symtab);
	condition->AnalyzeSemantic(&symtab);
	loop->AnalyzeSemantic(&symtab);
	body->AnalyzeSemantic(&symtab);

	/* Validate Condition Expression Type */
	if(!NOT_NULL_OF_TYPE(condition, EmptyExpressionNode*)) {
		Type condType = condition->GetValueType();
		if(!TypeNode::IsTypeCompatible(condType, Type::INTEGER)) {
			throw ASTException("cannot convert '" + std::string(TypeNode::GetTypeName(condType)) + "' to 'BOOL'.");
		}
	}
}

void ReturnStatementNode::AnalyzeSemantic(SymbolTable *intab) {
	
	exprStmt->AnalyzeSemantic(intab);
}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void ExpressionStatementNode::PrintContentInLevel(int level) const {
	if(NOT_NULL_OF_TYPE(expression, EmptyExpressionNode*)) {
		printf("Empty Statement\n");
	} else {
		printf("Expression Statement\n");

		PRINT_CHILD_WITH_HINT(expression, "EXPR");
	}
}

void CompoundStatementNode::PrintContentInLevel(int level) const {
	printf("Compound Statement\n");

	for(auto item : items) {
		PRINT_CHILD_WITH_HINT(item, "ITEM");
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

void ReturnStatementNode::PrintContentInLevel(int level) const {
	printf("Return Statement\n");

	PRINT_CHILD_WITH_HINT(exprStmt, "RETURN VALUE");
}

/*        PRINT FUNCTION END        */

/*        AUXILIARY FUNCTION        */

void CompoundStatementNode::AppendStatement(ASTNode *item) {
	assert(NOT_NULL_OF_TYPE(item, StatementNode*) ||
		   NOT_NULL_OF_TYPE(item, DeclarationNode*));
	items.push_back(item);
}

/*      AUXILIARY FUNCTION END      */
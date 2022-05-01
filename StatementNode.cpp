#include <stdio.h>
#include "DeclarationNode.h"
#include "StatementNode.h"

#define PRINT_CHILD_WITH_HINT(child, hint) \
	for(int i = 0; i < level; i++) printf("        "); \
	printf("| [" hint "]\n"); \
	child->PrintInLevel(level + 1);

/*         PRINT FUNCTION         */

void EmptyStatementNode::PrintContentInLevel(int level) const {
	printf("Empty Statement\n");
}

void CompoundStatementNode::PrintContentInLevel(int level) const {
	printf("Compound Statement\n");

	for(auto item : items) {
		item->PrintInLevel(level + 1);
	}
}

void ExpressionStatementNode::PrintContentInLevel(int level) const {
	printf("Expression Statement\n");
	
	expression->PrintInLevel(level + 1);
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
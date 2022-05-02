#include <stdio.h>
#include "DeclarationNode.h"
#include "ValueNode.h"

/*        CONSTRUCT FUNCTION        */

DeclarationNode::DeclarationNode(ASTNode *var, ASTNode *type, ASTNode *init)
	: ASTNode(), variable(var), type(type), initValue(init)
{
	assert(NOT_NULL_OF_TYPE(var, VariableNode*));
	assert(NOT_NULL_OF_TYPE(type, TypeNode*));
	assert(NULLABLE_OF_TYPE(init, ExpressionNode*));
}

/*      CONSTRUCT FUNCTION END      */

/*         PRINT FUNCTION         */

void DeclarationNode::PrintContentInLevel(int level) const {
	printf("Declaration\n");

	PRINT_CHILD_WITH_HINT(type, "TYPE");
	PRINT_CHILD_WITH_HINT(variable, "NAME");
	if(initValue) PRINT_CHILD_WITH_HINT(initValue, "INIT VALUE");
}

/*        PRINT FUNCTION END        */
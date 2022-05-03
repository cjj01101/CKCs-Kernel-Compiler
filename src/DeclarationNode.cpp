#include <stdio.h>
#include "DeclarationNode.h"
#include "StatementNode.h"
#include "ExpressionNode.h"

/*        CONSTRUCT FUNCTION        */

DeclarationNode::DeclarationNode(ASTNode *name, ASTNode *type, ASTNode *init)
	: ASTNode(), name(name), type(type), initValue(init)
{
	assert(NOT_NULL_OF_TYPE(name, IdentifierNode*));
	assert(NOT_NULL_OF_TYPE(type, TypeNode*));
	assert(NULLABLE_OF_TYPE(init, ExpressionNode*));
}

/*      CONSTRUCT FUNCTION END      */

/*         PRINT FUNCTION         */

void DeclarationNode::PrintContentInLevel(int level) const {
	printf("Declaration\n");

	PRINT_CHILD_WITH_HINT(type, "TYPE");
	PRINT_CHILD_WITH_HINT(name, "NAME");
	if(initValue) PRINT_CHILD_WITH_HINT(initValue, "INIT VALUE");
}

void TypeNode::PrintContentInLevel(int level) const {

	const static char *typeName[] = {
		#define TYPE(type) #type,
		TYPES
		#undef TYPE
	};

	printf("%s\n", typeName[static_cast<int>(type)]);

}

/*        PRINT FUNCTION END        */

/*        AUXILIARY FUNCTION        */

/*      AUXILIARY FUNCTION END      */
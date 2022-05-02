#include <stdio.h>
#include <cstring>
#include "ValueNode.h"

/*        CONSTRUCT FUNCTION        */

IdentifierNode::IdentifierNode(char *name) : ExpressionNode() {
	assert(name != NULL);
	strncpy(id, name, MAXVARLEN);
	id[MAXVARLEN-1] = '\0';
}

/*      CONSTRUCT FUNCTION END      */

/*         PRINT FUNCTION         */

void IntegerNode::PrintContentInLevel(int level) const {
	printf("[int] %d\n", num);
}

void IdentifierNode::PrintContentInLevel(int level) const {
	printf("[ID] %s\n", id);
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
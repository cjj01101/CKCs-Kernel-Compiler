#include <stdio.h>
#include <cstring>
#include "ValueNode.h"

/*        CONSTRUCT FUNCTION        */

VariableNode::VariableNode(char *name) : ASTNode() {
	assert(name != NULL);
	strncpy(id, name, MAXVARLEN);
	id[MAXVARLEN-1] = '\0';
}

/*      CONSTRUCT FUNCTION END      */

/*         PRINT FUNCTION         */

void EmptyExpressionNode::PrintContentInLevel(int level) const {
	printf("Empty Expression\n");
}

void IntegerNode::PrintContentInLevel(int level) const {
	printf("[int] %d\n", num);
}

void VariableNode::PrintContentInLevel(int level) const {
	printf("[var] %s\n", id);
}

void TypeNode::PrintContentInLevel(int level) const {

	switch(type){
	case Type::INTEGER: printf("INTEGER\n"); break;
	default: printf("UNDEFINED\n"); break;
	}

}

/*        PRINT FUNCTION END        */
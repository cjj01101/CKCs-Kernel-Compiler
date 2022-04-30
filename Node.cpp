#include <stdio.h>
#include <cstring>
#include "ASTNode.h"
#include "ValueNode.h"
#include "OperatorNode.h"
#include "DeclarationNode.h"

/*        CONSTRUCT FUNCTION        */

VariableNode::VariableNode(char *name) : ASTNode() {
	assert(name != NULL);
	strncpy(id, name, MAXVARLEN);
	id[MAXVARLEN-1] = '\0';
}

/*      CONSTRUCT FUNCTION END      */

/*         PRINT FUNCTION         */

void ASTNode::PrintInLevel(int level) const {
	for(int i = 0; i < level; i++) {
		if(i == level - 1) printf("+-------");
		else printf("|       ");
	}
	PrintContentInLevel(level);
}

void EmptyExpressionNode::PrintContentInLevel(int level) const {
	printf("Empty Expression\n");
}

void IntegerNode::PrintContentInLevel(int level) const {
	printf("%d\n", num);
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

void BinaryOpNode::PrintContentInLevel(int level) const {

	const static char *OperatorName[] = {
		#define OP(op) #op,
		OPERATORS
		#undef OP
	};

	printf("%s\n", OperatorName[static_cast<int>(op)]);

	if(leftOperand) leftOperand->PrintInLevel(level + 1);
	if(rightOperand) rightOperand->PrintInLevel(level + 1);

}

void AssignOpNode::PrintContentInLevel(int level) const {
	printf("Assign\n");

	leftValue->PrintInLevel(level + 1);
	rightValue->PrintInLevel(level + 1);
}

void DeclarationNode::PrintContentInLevel(int level) const {
	printf("Declaration\n");

	type->PrintInLevel(level + 1);
	variable->PrintInLevel(level + 1);
}

/*        PRINT FUNCTION END        */

/*        AUXILIARY FUNCTION        */



/*      AUXILIARY FUNCTION END      */
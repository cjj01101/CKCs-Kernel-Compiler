#include <stdio.h>
#include "ASTNode.h"
#include "OperatorNode.h"
#include "DeclarationNode.h"

/*         PRINT FUNCTION         */

void ASTNode::PrintInLevel(int level) const {
	for(int i = 0; i < level; i++) {
		if(i == level - 1) printf("+-------");
		else printf("|       ");
	}
	PrintContentInLevel(level);
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
	printf("Assign Expression\n");

	leftValue->PrintInLevel(level + 1);
	rightValue->PrintInLevel(level + 1);
}

void DeclarationNode::PrintContentInLevel(int level) const {
	printf("Declaration\n");

	type->PrintInLevel(level + 1);
	variable->PrintInLevel(level + 1);
}

/*        PRINT FUNCTION END        */
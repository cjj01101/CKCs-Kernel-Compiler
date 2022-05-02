#include <stdio.h>
#include "OperatorNode.h"

/*         PRINT FUNCTION         */

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

/*        PRINT FUNCTION END        */
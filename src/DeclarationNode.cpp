#include <stdio.h>
#include "DeclarationNode.h"

/*         PRINT FUNCTION         */

void DeclarationNode::PrintContentInLevel(int level) const {
	printf("Declaration\n");

	type->PrintInLevel(level + 1);
	variable->PrintInLevel(level + 1);
}

/*        PRINT FUNCTION END        */
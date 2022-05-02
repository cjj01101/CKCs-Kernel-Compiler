#include <stdio.h>
#include "ASTNode.h"
#include "DeclarationNode.h"

/*         PRINT FUNCTION         */

void ASTNode::PrintInLevel(int level) const {
	for(int i = 0; i < level; i++) {
		if(i == level - 1) printf("+-------");
		else printf("|       ");
	}
	PrintContentInLevel(level);
}

void DeclarationNode::PrintContentInLevel(int level) const {
	printf("Declaration\n");

	type->PrintInLevel(level + 1);
	variable->PrintInLevel(level + 1);
}

/*        PRINT FUNCTION END        */
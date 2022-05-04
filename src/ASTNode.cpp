#include <stdio.h>
#include "ASTNode.h"

/*         PRINT FUNCTION         */

void ASTNode::PrintInLevel(int level) const {
	for(int i = 0; i < level; i++) {
		if(i == level - 1) printf("+-------");
		else printf("|       ");
	}
	PrintContentInLevel(level);
}

void ASTException::PrintMessage() const {
	printf("%s\n", message.c_str());
}

/*        PRINT FUNCTION END        */
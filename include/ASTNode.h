#ifndef _ASTNODE_H_
#define _ASTNODE_H_

#include <assert.h>
#include "common.h"

#define PRINT_CHILD_WITH_HINT(child, hint) \
	do { \
		for(int i = 0; i < level; i++) printf("|       "); \
		printf("| [" hint "]\n"); \
		child->PrintInLevel(level + 1); \
	} while(0)

#define NOT_NULL_OF_TYPE(node, type) \
	(dynamic_cast<type>(node) != nullptr)

#define NULLABLE_OF_TYPE(node, type) \
	(node == nullptr || dynamic_cast<type>(node) != nullptr)

class ASTNode {

public:
	ASTNode() {}
	virtual ~ASTNode() {}

	void PrintInLevel(int level) const;

protected:
	
	virtual void PrintContentInLevel(int level) const = 0;

};

#endif
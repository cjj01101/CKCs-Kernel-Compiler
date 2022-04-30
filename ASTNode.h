#ifndef _ASTNODE_H_
#define _ASTNODE_H_

#include <assert.h>

class ASTNode {

public:
	ASTNode() {}
	virtual ~ASTNode() {}

	void PrintInLevel(int level) const;

protected:
	
	virtual void PrintContentInLevel(int level) const = 0;

};

#endif
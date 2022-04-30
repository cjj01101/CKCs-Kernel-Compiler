#ifndef _ASTNODE_H_
#define _ASTNODE_H_

#include <iostream>
#include <assert.h>
using namespace std;

class ASTNode {

public:
	ASTNode() {}
	virtual ~ASTNode() {}

	void PrintInLevel(int level) {
		for(int i = 0; i < level; i++) {
			if(i == level - 1) cout << "+-------";
			else cout << "|       ";
		}
		PrintContentInLevel(level);
	}

protected:
	
	virtual void PrintContentInLevel(int level) = 0;

};

#endif
#ifndef _ASTNODE_H_
#define _ASTNODE_H_

#include <iostream>
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
		PrintContent();
		PrintChildren(level);
	}

protected:
	
	virtual void PrintContent() = 0;
	virtual void PrintChildren(int level) {}

};

#endif
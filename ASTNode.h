#ifndef _ASTNODE_H_
#define _ASTNODE_H_

#include <iostream>
using namespace std;

class ASTNode {

public:
	ASTNode(ASTNode *left = nullptr, ASTNode *right = nullptr) :
		leftChild(left), rightChild(right) {}
	~ASTNode() {
		delete leftChild;
		delete rightChild;
	}

	void PrintInLevel(int level) {
		for(int i = 0; i < level; i++) {
			if(i == level - 1) cout << "+-------";
			else cout << "|       ";
		}
		PrintContent();
		if(leftChild) leftChild->PrintInLevel(level + 1);
		if(rightChild) rightChild->PrintInLevel(level + 1);
	}

protected:
	ASTNode *leftChild;
	ASTNode *rightChild;

	virtual void PrintContent() = 0;
};

#endif
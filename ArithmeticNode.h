#ifndef _ARITHMETIC_NODE_H_
#define _ARITHMETIC_NODE_H_

#include "ASTNode.h"

class IntegerNode : public ASTNode {

public:
	IntegerNode(int num, ASTNode *left = nullptr, ASTNode *right = nullptr) :
		ASTNode(left, right), num(num) {}
	~IntegerNode() {}

private:
	int num;

	void PrintContent() { cout << num << endl; }

};

class ArithOpNode : public ASTNode {

public:
	ArithOpNode(char op, ASTNode *left = nullptr, ASTNode *right = nullptr) :
		ASTNode(left, right), op(op) {}
	~ArithOpNode() {}

private:
	char op;

	void PrintContent() {
		switch(op){
		case '+':
			cout << "ADD" << endl;
			break;
		case '-':
			cout << "SUB" << endl;
			break;
		case '*':
			cout << "MUL" << endl;
			break;
		case '/':
			cout << "DIV" << endl;
			break;
		}
		
	}

};

#endif
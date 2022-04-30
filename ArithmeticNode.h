#ifndef _ARITHMETIC_NODE_H_
#define _ARITHMETIC_NODE_H_

#include "ASTNode.h"

class IntegerNode : public ASTNode {

public:
	IntegerNode(int num) : ASTNode(), num(num) {}
	~IntegerNode() {}

private:
	int num;

	virtual void PrintContent() override { cout << num << endl; }

};

class ArithOpNode : public ASTNode {

public:
	ArithOpNode(char op, ASTNode *left = nullptr, ASTNode *right = nullptr) :
		ASTNode(), leftOperand(left), rightOperand(right), op(op) {}
	~ArithOpNode() {}

private:
	ASTNode *leftOperand;
	ASTNode *rightOperand;
	char op;

	virtual void PrintContent() override {
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

	virtual void PrintChildren(int level) override {
		if(leftOperand) leftOperand->PrintInLevel(level + 1);
		if(rightOperand) rightOperand->PrintInLevel(level + 1);
	}

};

#endif
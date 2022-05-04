#ifndef _ABSTRACT_SYNTAX_TREE_H_
#define _ABSTRACT_SYNTAX_TREE_H_

#include "ASTNode.h"

class AbstractSyntaxTree {

public:
	AbstractSyntaxTree(ASTNode *root = nullptr) : root(root) {}
	~AbstractSyntaxTree() { delete root; }

	void Print() { if(root) root->PrintInLevel(0); }
	void AnalyzeSemantic() {
		if(root) {
			try {
				SymbolTable symtab;
				root->AnalyzeSemantic(&symtab);
			} catch (ASTException &e) {
				e.PrintMessage();
			}
		}
	}

private:
	ASTNode *root;

};

#endif
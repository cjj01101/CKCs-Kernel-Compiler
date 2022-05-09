#ifndef _ABSTRACT_SYNTAX_TREE_H_
#define _ABSTRACT_SYNTAX_TREE_H_

#include "ASTNode.h"

class CodeGenerator;

class AbstractSyntaxTree {

public:
	AbstractSyntaxTree(ASTNode *root = nullptr) : root(root) {}
	~AbstractSyntaxTree() { delete root; }

	void Print() { if(root) root->PrintInLevel(0); }
	void AnalyzeSemantic() { if(root) { SymbolTable symtab; root->AnalyzeSemantic(&symtab); } }
	void CodeGen(CodeGenerator *generator) { if(root) root->CodeGen(generator); }

private:
	ASTNode *root;

};

#endif
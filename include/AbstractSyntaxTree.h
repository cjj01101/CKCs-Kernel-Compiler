#ifndef _ABSTRACT_SYNTAX_TREE_H_
#define _ABSTRACT_SYNTAX_TREE_H_

#include "ASTNode.h"

class SemanticAnalyzer;
class CodeGenerator;

class AbstractSyntaxTree {

public:
	AbstractSyntaxTree(ASTNode *root = nullptr) : root(root) {}
	~AbstractSyntaxTree() { delete root; }

	void Print() { if(root) root->PrintInLevel(0); }
	void AnalyzeSemantic(SemanticAnalyzer *analyzer) { if(root) { root->AnalyzeSemantic(analyzer); } }
	void GenerateIR(CodeGenerator *generator) { if(root) root->GenerateIR(generator); }

private:
	ASTNode *root;

};

#endif
#ifndef _PROGRAM_NODE_H_
#define _PROGRAM_NODE_H_

#include <vector>
#include "ASTNode.h"

class TranslationUnitNode : public ASTNode {

public:
	TranslationUnitNode() : ASTNode(), definitions() {}
	~TranslationUnitNode() {}

	void AppendDefinition(ASTNode *def);

	virtual void AnalyzeSemantic(SymbolTable *intab) override;

private:
	std::vector<ASTNode*> definitions;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
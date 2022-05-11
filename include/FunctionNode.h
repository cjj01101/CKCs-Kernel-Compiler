#ifndef _FUNCTION_NODE_H_
#define _FUNCTION_NODE_H_

#include <vector>
#include "ASTNode.h"

class FunctionNode : public ASTNode {

public:
	FunctionNode(TypeNode *returnType, IdentifierNode *name, ParameterListNode *parameters, CompoundStatementNode *body);
	~FunctionNode();

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;
	
private:
	TypeNode *returnType;
	IdentifierNode *name;
	ParameterListNode *parameters;
	CompoundStatementNode *body;

	virtual void PrintContentInLevel(int level) const override;

};

class ParameterListNode : public ASTNode {

	friend class FunctionNode;

public:
	ParameterListNode() : ASTNode(), parameters() {}
	~ParameterListNode();

	void AppendParameter(DeclarationNode *param);

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *GenerateIR(CodeGenerator *generator) override;

private:
	std::vector<DeclarationNode*> parameters;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
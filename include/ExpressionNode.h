#ifndef _EXPRESSION_NODE_H_
#define _EXPRESSION_NODE_H_

#include <vector>
#include "ASTNode.h"

class ExpressionNode : public ASTNode {

public:
	ExpressionNode() : ASTNode(), valueType(Type::VOID) {}
	virtual ~ExpressionNode() {}
	virtual llvm::Value *CodeGen() override;
	
	Type GetValueType() { return valueType; }

protected:
	Type valueType;

};

class EmptyExpressionNode : public ExpressionNode {

public:
	EmptyExpressionNode() : ExpressionNode() {}
	~EmptyExpressionNode() {}

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen() override;
	
private:
	virtual void PrintContentInLevel(int level) const override;

};

class IdentifierNode : public ExpressionNode {

public:
	IdentifierNode(char *name);
	~IdentifierNode() {}

	char *GetName() { return id; }

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen() override;
	
private:
	char id[MAXVARLEN];

	virtual void PrintContentInLevel(int level) const override;

};

#endif
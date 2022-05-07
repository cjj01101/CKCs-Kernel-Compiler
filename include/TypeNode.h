#ifndef _TYPE_NODE_H_
#define _TYPE_NODE_H_

#include "ASTNode.h"

class TypeNode : public ASTNode {

public:
	TypeNode(Type type) : ASTNode(), type(type) { }
	~TypeNode() {}

	Type GetType() { return type; }
	
	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen() override;	

	static const char *GetTypeName(Type type);
	static bool IsTypeCompatible(Type first, Type second);
	static Type GetPromotedTypeBetween(Type first, Type second);
	static llvm::Type *ConvertToLLVMType(Type type);
	static llvm::Type *ConverToLLVMPtrType(Type type);
	static llvm::Constant *initValue(Type type);

private:
	Type type;

	virtual void PrintContentInLevel(int level) const override;

};

#endif
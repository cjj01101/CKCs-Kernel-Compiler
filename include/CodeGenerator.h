#ifndef _CODE_GENERATOR_H_
#define _CODE_GENERATOR_H_

#include <unordered_map>
#include <string>

#include "llvm/IR/IRBuilder.h"
#include "common.h"

class CodeGenerator {

public:
	using ValueTable = std::unordered_map<std::string, llvm::Value*>;

	CodeGenerator() : context(), module("CKC IR Code", context), builder(context), initializer(nullptr), tables() {}
	~CodeGenerator() {}

	static void InitializeLLVM();
	void PrintIR();

	llvm::Type *ConvertToLLVMType(Type type);
	llvm::Type *ConvertToLLVMPtrType(Type type);
	llvm::Constant *GetTypeDefaultValue(Type type);

	llvm::Value *CastValueType(llvm::Value *origin, Type from, Type to);

	llvm::Function *GetCurrentFunction() { return builder.GetInsertBlock()->getParent(); }
	llvm::BasicBlock *CreateBasicBlock(const char *name, llvm::Function *function = nullptr)
		{ return llvm::BasicBlock::Create(context, name, function ? function : GetCurrentFunction()); }

	void SetGlobalInitializerPoint(llvm::Instruction *inst) { initializer = inst; }
	void JumpToBlock(llvm::BasicBlock *block) { builder.SetInsertPoint(block); }
	void JumpToGlobalInitializer() { builder.SetInsertPoint(initializer); }
	void JumpToVoid() { builder.ClearInsertionPoint(); }

	void AddNewTable() { tables.push_back(ValueTable()); }
	void RemoveTable() { tables.pop_back(); }
	void RecordValue(const std::string &name, llvm::Value *value) { tables.back().insert({name, value}); }
	llvm::Value *FindValue(const std::string &name);

private:

	llvm::LLVMContext context;

public:

	llvm::Module module;
	llvm::IRBuilder<> builder;

private:

	llvm::Instruction *initializer;
	std::vector<ValueTable> tables;

};

#endif
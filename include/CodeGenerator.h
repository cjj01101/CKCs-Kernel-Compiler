#ifndef _CODE_GENERATOR_H_
#define _CODE_GENERATOR_H_

#include <unordered_map>
#include <string>

#include "llvm/IR/IRBuilder.h"
#include "common.h"

class CodeGenerator {

public:
	using ValueTable = std::unordered_map<std::string, llvm::Value*>;

	CodeGenerator() : context(), module("IR", context), builder(context) {}
	~CodeGenerator() {}

	static void InitializeLLVM();
	void PrintIR();

	llvm::Type *ConvertToLLVMType(Type type);
	llvm::Type *ConvertToLLVMPtrType(Type type);
	llvm::Constant *GetTypeDefaultValue(Type type);

	llvm::Value *CastValueType(llvm::Value *origin, Type from, Type to);

	llvm::Function *GetCurrentFunction() { return builder.GetInsertBlock()->getParent(); }
	llvm::BasicBlock *CreateBasicBlock(const char *name)
		{ return llvm::BasicBlock::Create(context, name, GetCurrentFunction()); }

	void SetGlobalInsertionPoint(llvm::Instruction *inst) { init = inst; }
	void JumpToBlock(llvm::BasicBlock *block) { builder.SetInsertPoint(block); }
	void JumpToInitializer() { builder.SetInsertPoint(init); }
	void JumpToVoid() { builder.ClearInsertionPoint(); }

	void AddNewTable() { tables.push_back(ValueTable()); }
	void RemoveTable() { tables.pop_back(); }
	void RecordValue(const std::string &name, llvm::Value *value) { tables.back().insert({name, value}); }
	llvm::Value *FindValue(const std::string &name) {
		for(auto it = tables.rbegin(); it != tables.rend(); it++)
			if(it->find(name) != it->end()) return it->at(name);
		return nullptr;
	}

	llvm::LLVMContext context;
	llvm::Module module;
	llvm::IRBuilder<> builder;

private:
	llvm::Instruction *init;
	std::vector<ValueTable> tables;

};

#endif
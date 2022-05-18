#ifndef _CODE_GENERATOR_H_
#define _CODE_GENERATOR_H_

#include <unordered_map>
#include <string>

#include "llvm/IR/IRBuilder.h"
#include "common.h"

class CodeGenerator {

public:
	using ValueTable = std::unordered_map<std::string, llvm::Value*>;

	CodeGenerator();
	~CodeGenerator() {}

	static void InitializeLLVM();
	void PrintIR();
	void OptimizeIR();
	void GenerateTarget(const char *filename = "cc.o");

	llvm::Type *ConvertToLLVMType(Type type);
	llvm::Type *ConvertToLLVMPtrType(Type type);
	llvm::Constant *GetTypeDefaultValue(Type type)
		{ return llvm::Constant::getNullValue(ConvertToLLVMType(type)); }

	llvm::Value *CastValueType(llvm::Value *origin, Type from, Type to);
	llvm::Value *CastValueType(llvm::Value *origin, Type from, llvm::Type *to);

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

	void PushLoopTargets(llvm::BasicBlock* cond, llvm::BasicBlock *after)
		{ continueTargets.push_back(cond); breakTargets.push_back(after); }
	void PopLoopTargets() { continueTargets.pop_back(); breakTargets.pop_back(); }
	llvm::BasicBlock* GetBreakTarget() { return breakTargets.back(); }
	llvm::BasicBlock* GetContinueTarget() { return continueTargets.back(); }

public:

	llvm::LLVMContext context;

public:

	llvm::Module module;
	llvm::IRBuilder<> builder;

private:

	llvm::Instruction *initializer;
	std::vector<ValueTable> tables;
	std::vector<llvm::BasicBlock*> breakTargets;
	std::vector<llvm::BasicBlock*> continueTargets;

};

#endif
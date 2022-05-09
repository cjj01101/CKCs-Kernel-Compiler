#ifndef _CODE_GENERATOR_H_
#define _CODE_GENERATOR_H_

#include <map>
#include <string>

#include "llvm/IR/IRBuilder.h"
#include "common.h"

/* FORWARD DECLARATION */
namespace llvm {
	class Value;
	class LLVMContext;
	class Module;
};
/* FORWARD DECLARATION */

class CodeGenerator {

public:
	CodeGenerator() : context(), module("IR", context), builder(context) {}
	~CodeGenerator() {}

	static void InitializeLLVM();
	void PrintIR();

	llvm::Type *ConvertToLLVMType(Type type);
	llvm::Type *ConvertToLLVMPtrType(Type type);
	llvm::Constant *GetTypeDefaultValue(Type type);

	llvm::LLVMContext context;
	llvm::Module module;
	llvm::IRBuilder<> builder;

};

#endif
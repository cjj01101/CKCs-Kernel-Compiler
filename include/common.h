#ifndef _COMMON_H_
#define _COMMON_H_

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/ValueSymbolTable.h"
#include "llvm/Support/TargetSelect.h"

/* FORWARD DECLARATION */
class ASTNode;
class TypeNode;
class IdentifierNode;
class ParameterListNode;
class ArgumentListNode;
class ExpressionNode;
class StatementNode;
class CompoundStatementNode;
class DeclarationNode;
class TranslationUnitNode;
/* FORWARD DECLARATION */

#define MAXVARLEN 64

#define TYPES \
	TYPE(INTEGER) TYPE(FLOAT) TYPE(VOID)

#define OPERATORS \
	OP(LOGOR) OP(LOGAND) \
	OP(OR) OP(XOR) OP(AND) OP(NOT) \
	OP(EQ) OP(NEQ) \
	OP(LT) OP(LTE) OP(GT) OP(GTE) \
	OP(ADD) OP(SUB) OP(MUL) OP(DIV) OP(MOD)

enum class Type : unsigned char {
	#define TYPE(type) type,
	TYPES
	#undef TYPE
};

enum class Operator : unsigned char {
	#define OP(op) op,
	OPERATORS
	#undef OP
};

#endif
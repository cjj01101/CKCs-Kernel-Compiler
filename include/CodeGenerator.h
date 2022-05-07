#ifndef _CODE_GENERATOR_H_
#define _CODE_GENERATOR_H_

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "ASTNode.h"
#include "ConstantNode.h"
#include "DeclarationNode.h"
#include "ExpressionNode.h"
#include "FunctionNode.h"
#include "OperatorNode.h"
#include "StatementNode.h"
#include "TranslationUnitNode.h"
#include "TypeNode.h"

static std::unique_ptr<llvm::LLVMContext> TheContext;
static std::unique_ptr<llvm::IRBuilder<>> Builder;
static std::unique_ptr<llvm::Module> TheModule;
static std::map<std::string, llvm::Value *> NamedValues;

llvm::Value *LogErrorV(const char *Str);

void Info(const char *Str);

void InitializeModule();

void Generate(ASTNode *root);


#endif
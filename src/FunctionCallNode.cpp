#include <assert.h>
#include <stdio.h>
#include "FunctionCallNode.h"
#include "ExpressionNode.h"
#include "Utility.h"
#include "SemanticAnalyzer.h"
#include "CodeGenerator.h"

/*      (DE)CONSTRUCT FUNCTION      */

FunctionCallNode::FunctionCallNode(IdentifierNode *name, ArgumentListNode *arguments)
	: ExpressionNode(), name(name), arguments(arguments)
{
	assert(NOT_NULL(name));
	assert(NOT_NULL(arguments));
}

FunctionCallNode::~FunctionCallNode() {
	delete name;
	delete arguments;
}

ArgumentListNode::~ArgumentListNode() {
	for(auto arg : arguments) delete arg;
}

PutiCallNode::PutiCallNode(ExpressionNode *num)
	: ExpressionNode(), num(num)
{
	assert(NOT_NULL(num));
}

PutiCallNode::~PutiCallNode() {
	delete num;
}

/*    (DE)CONSTRUCT FUNCTION END    */

/*         SEMANTIC ANALYZE         */

void FunctionCallNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {

	arguments->AnalyzeSemantic(analyzer);

	/* Start Type Checking */
	char message[128];

	/* Check Symbol Kind */
	char *fname = name->GetName();
	std::string sym(fname);

	auto occtab = analyzer->FindSymbolOccurrence(sym);
	if(occtab == analyzer->NoTable()) {
		throw ASTException("'" + sym + "' was not declared in this scope.");
	} 

	const auto &symbolContent = occtab->at(sym);
	if(symbolContent.kind != SymbolKind::FUNCTION) {
		sprintf(message, "'%s' is not a function.", fname);
		throw ASTException(message);
	}
	
	/* Get Parameter Types */
	const auto &paramTypes = symbolContent.type.argTypes;
	int paramNum = paramTypes.size();

	/* Get Argument Types*/
	std::vector<Type> argTypes;
	for(auto arg : arguments->arguments) {
		argTypes.push_back(arg->GetValueType());
	}
	int argNum = argTypes.size();

	/* Validate Argument Types */
	if(argNum != paramNum) {
		sprintf(message, "function %s expects %d arguments, %d provided.", fname, paramNum, argNum);
		throw ASTException(message);
	}

	for(int i = 0; i < paramNum; i++) {
		if(!TypeUtils::CanConvert(argTypes[i], paramTypes[i])) {
			sprintf(message, "cannot convert '%s' to '%s' in call to function %s.",
				TypeUtils::GetTypeName(argTypes[i]), TypeUtils::GetTypeName(paramTypes[i]), fname);
			throw ASTException(message);
		}
	}

	/* Determine Value Type */
	valueType = symbolContent.type.type;
}

void ArgumentListNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {

	for(auto arg : arguments) arg->AnalyzeSemantic(analyzer);
}

void PutiCallNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {

	num->AnalyzeSemantic(analyzer);

	/* Get Argument Types*/
	if(!TypeUtils::CanConvert(num->GetValueType(), Type::INTEGER)) {
		char message[128];
		sprintf(message, "cannot convert '%s' to '%s' in call to function puti.",
			TypeUtils::GetTypeName(num->GetValueType()), TypeUtils::GetTypeName(Type::INTEGER));
		throw ASTException(message);
	}

	/* Determine Value Type */
	valueType = Type::VOID;
}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void FunctionCallNode::PrintContentInLevel(int level) const {
	printf("Function Call\n");

	PRINT_CHILD_WITH_HINT(name, "NAME");
	PRINT_CHILD_WITH_HINT(arguments, "ARGS");
}

void ArgumentListNode::PrintContentInLevel(int level) const {
	printf("Argument List\n");

	for(auto arg : arguments) {
		PRINT_CHILD_WITH_HINT(arg, "ARG");
	}
}

void PutiCallNode::PrintContentInLevel(int level) const {
	printf("Puti Call\n");

	PRINT_CHILD_WITH_HINT(num, "ARG EXPR");
}

/*        PRINT FUNCTION END        */

/*         GENERATE IR CODE         */

llvm::Value *FunctionCallNode::GenerateIR(CodeGenerator *generator) {

    llvm::Function *function = generator->module.getFunction(std::string(name->GetName()));
    const std::vector<llvm::Type*> paramTypes = function->getFunctionType()->params();

    std::vector<llvm::Value *> args;
    for(int i = 0; i < arguments->arguments.size(); i++) {
    	auto arg = arguments->arguments[i];
    	llvm::Value *argValue = arg->GenerateIR(generator);
    	argValue = generator->CastValueType(argValue, arg->GetValueType(), paramTypes[i]);
        args.push_back(argValue);
    }

    return generator->builder.CreateCall(function, args, "calltmp");
}

llvm::Value *ArgumentListNode::GenerateIR(CodeGenerator *generator) {
    return nullptr;
}

llvm::Value *PutiCallNode::GenerateIR(CodeGenerator *generator) {

    llvm::Function *function = generator->module.getFunction(std::string("printf"));
    
    llvm::Value *argValue = num->GenerateIR(generator);
    argValue = generator->CastValueType(argValue, num->GetValueType(), Type::INTEGER);

    std::string format("Put Value = %d\n");
    auto formatConst = llvm::ConstantDataArray::getString(generator->context, format.c_str());
    auto formatArg = new llvm::GlobalVariable(generator->module, llvm::ArrayType::get(generator->builder.getInt8Ty(), format.size() + 1), true, llvm::GlobalValue::ExternalLinkage, formatConst, ".str");
    auto zero = generator->GetTypeDefaultValue(Type::INTEGER);
    llvm::Constant* indices[] = {zero, zero};
    static auto varRef = llvm::ConstantExpr::getGetElementPtr(formatArg->getType()->getPointerElementType(), formatArg, indices);

    return generator->builder.CreateCall(function, {varRef, argValue}, "puti");
}

/*       GENERATE IR CODE END       */

/*        AUXILIARY FUNCTION        */

void ArgumentListNode::AppendArgument(ExpressionNode *arg) {
	assert(NOT_NULL(arg));
	arguments.push_back(arg);
}

/*      AUXILIARY FUNCTION END      */
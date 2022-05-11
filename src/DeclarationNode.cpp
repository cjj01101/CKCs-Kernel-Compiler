#include <assert.h>
#include <stdio.h>
#include "DeclarationNode.h"
#include "StatementNode.h"
#include "ExpressionNode.h"
#include "TypeNode.h"
#include "Utility.h"
#include "SemanticAnalyzer.h"
#include "CodeGenerator.h"

using namespace TypeUtils;

/*      (DE)CONSTRUCT FUNCTION      */

DeclarationNode::DeclarationNode(TypeNode *type, DeclaratorListNode *declarators)
	: ASTNode(), type(type), declarators(declarators)
{
	assert(NOT_NULL(type));
	assert(NOT_NULL(declarators));
}

DeclarationNode::~DeclarationNode() {
	delete type;
    delete declarators;
}

DeclaratorListNode::~DeclaratorListNode() {
    for(auto decl : declarators) {
        delete decl.name;
        delete decl.initValue;
    }
}

/*    (DE)CONSTRUCT FUNCTION END    */

/*         SEMANTIC ANALYZE         */

void DeclarationNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {

    /* Verify Declaration Type */
    Type dtype = type->GetType();
    if(dtype == Type::VOID) {
        throw ASTException("variable or argument declared void.");
    }

    for(auto decl : declarators->declarators) {

        /* Check Symbol Redefinition */
        std::string sym(decl.name->GetName());
        if(analyzer->HasSymbol(sym)) {
            throw ASTException("redeclaration of symbol '" + sym + "'.");
        }

        /* Verify Operand Types */
        if(decl.initValue) {
            decl.initValue->AnalyzeSemantic(analyzer);

            Type initType = decl.initValue->GetValueType();
            if(!CanConvert(initType, dtype)) {
                char message[128];
                sprintf(message, "cannot convert '%s' to '%s' in initialization.",
                    GetTypeName(initType), GetTypeName(dtype));
                throw ASTException(message);
            }
        }

        /* Update Symbol Table */
        analyzer->AddSymbol(sym, SymbolTableEntry(SymbolKind::VARIABLE, dtype));
    }
}

void DeclaratorListNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {
    
}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void DeclarationNode::PrintContentInLevel(int level) const {
	printf("Declaration\n");

	PRINT_CHILD_WITH_HINT(type, "TYPE");
    PRINT_CHILD_WITH_HINT(declarators, "SYMBOLS");
}

void DeclaratorListNode::PrintContentInLevel(int level) const {
    printf("Declared Symbols\n");

    for(auto decl : declarators) {
        PRINT_CHILD_WITH_HINT(decl.name, "NAME");
        if(decl.initValue) PRINT_CHILD_WITH_HINT(decl.initValue, "INIT VALUE");
    }
}

/*        PRINT FUNCTION END        */

/*         GENERATE IR CODE         */

llvm::Value *DeclarationNode::GenerateIR(CodeGenerator *generator) {
    
    Type dtype = type->GetType();

    for(auto decl : declarators->declarators) {

        std::string dname = std::string(decl.name->GetName());
        ExpressionNode *initValue = decl.initValue;

        llvm::Value *var = nullptr;

        /* Local Varible */
        if(generator->builder.GetInsertBlock()) {

            var = generator->builder.CreateAlloca(generator->ConvertToLLVMType(dtype), nullptr, dname);

            if (initValue) {
                llvm::Value *R = initValue->GenerateIR(generator);
                R = generator->CastValueType(R, initValue->GetValueType(), dtype);
                generator->builder.CreateStore(R, var);
            }
        }

        /* Global Varible */
        else {
            var = new llvm::GlobalVariable(generator->module,
                                           generator->ConvertToLLVMType(type->GetType()),
                                           false,
                                           llvm::GlobalValue::ExternalLinkage,
                                           generator->GetTypeDefaultValue(type->GetType()),
                                           dname);

            if (initValue) {
                generator->JumpToGlobalInitializer();
                llvm::Value *R = initValue->GenerateIR(generator);
                R = generator->CastValueType(R, initValue->GetValueType(), dtype);
                generator->builder.CreateStore(R, var);
                generator->JumpToVoid();
            }
        }

        generator->RecordValue(dname, var);
    }
    
    return nullptr;
}

llvm::Value *DeclaratorListNode::GenerateIR(CodeGenerator *generator) {
    return nullptr;
}

/*       GENERATE IR CODE END       */

/*        AUXILIARY FUNCTION        */

Type DeclarationNode::GetType() {
	return type->GetType();
}

char *DeclarationNode::GetName() {
	return declarators->declarators[0].name->GetName();
}

void DeclaratorListNode::AppendDeclarator(const Declarator &declarator) {
    declarators.push_back(declarator);
}

/*      AUXILIARY FUNCTION END      */
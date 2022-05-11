#include <assert.h>
#include <stdio.h>
#include "TranslationUnitNode.h"
#include "DeclarationNode.h"
#include "FunctionNode.h"
#include "CodeGenerator.h"

/*         SEMANTIC ANALYZE         */

void TranslationUnitNode::AnalyzeSemantic(SymbolTable *intab) {
    for(auto def : definitions) {
    	def->AnalyzeSemantic(intab);
    }

    if(!intab->HasSymbol(std::string(ENTRANCE))) {
        throw ASTException("definition of entrance function '" ENTRANCE "' not found.");
    }
}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void TranslationUnitNode::PrintContentInLevel(int level) const {
	printf("[Root] Translation Unit Starts Here!\n");

	for(auto def : definitions) {
		PRINT_CHILD_WITH_HINT(def, "EXTERNAL DEFINITION");
	}
}

/*        PRINT FUNCTION END        */

/*         GENERATE IR CODE         */

llvm::Value *TranslationUnitNode::GenerateIR(CodeGenerator *generator) {

    /* Create Global Initialization Function */
    llvm::FunctionType *funcType = llvm::FunctionType::get(generator->builder.getVoidTy(), false);
    llvm::Function *function = llvm::Function::Create(funcType,
                                                      llvm::Function::InternalLinkage,
                                                      GLOBALINIT,
                                                      &generator->module);
    llvm::BasicBlock *funcBody = generator->CreateBasicBlock("", function);

    generator->JumpToBlock(funcBody);
    llvm::ReturnInst *ret = generator->builder.CreateRetVoid();
    generator->SetGlobalInitializerPoint(ret);
    generator->JumpToVoid();

    /* Start Generating Code */
    generator->AddNewTable();
    for (auto def : definitions) def->GenerateIR(generator);
    generator->RemoveTable();

    return nullptr;
}

/*       GENERATE IR CODE END       */

/*        AUXILIARY FUNCTION        */

void TranslationUnitNode::AppendDefinition(ASTNode *def) {
	assert(NOT_NULL_OF_TYPE(def, FunctionNode*) ||
		   NOT_NULL_OF_TYPE(def, DeclarationNode*));
	definitions.push_back(def);
}

/*      AUXILIARY FUNCTION END      */
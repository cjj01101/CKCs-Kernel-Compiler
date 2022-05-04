#include <assert.h>
#include <stdio.h>
#include "TranslationUnitNode.h"
#include "DeclarationNode.h"
#include "FunctionNode.h"

/*         SEMANTIC ANALYZE         */

void TranslationUnitNode::AnalyzeSemantic(SymbolTable *intab) {
	for(auto def : definitions) {
		def->AnalyzeSemantic(intab);
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

/*        AUXILIARY FUNCTION        */

void TranslationUnitNode::AppendDefinition(ASTNode *def) {
	assert(NOT_NULL_OF_TYPE(def, FunctionNode*) ||
		   NOT_NULL_OF_TYPE(def, DeclarationNode*));
	definitions.push_back(def);
}

/*      AUXILIARY FUNCTION END      */
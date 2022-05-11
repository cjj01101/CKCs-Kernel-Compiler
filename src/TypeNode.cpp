#include "TypeNode.h"
#include "Utility.h"
#include "CodeGenerator.h"

/*         SEMANTIC ANALYZE         */

void TypeNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {
	
}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void TypeNode::PrintContentInLevel(int level) const {

	printf("%s\n", TypeUtils::GetTypeName(type));

}

/*        PRINT FUNCTION END        */

/*         GENERATE IR CODE         */

llvm::Value *TypeNode::GenerateIR(CodeGenerator *generator) {
    return nullptr;
}

/*       GENERATE IR CODE END       */

/*        AUXILIARY FUNCTION        */

/*      AUXILIARY FUNCTION END      */
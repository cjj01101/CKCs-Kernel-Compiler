#include "TypeNode.h"
#include "Utility.h"

/*         SEMANTIC ANALYZE         */

void TypeNode::AnalyzeSemantic(SymbolTable *intab) {
	
}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void TypeNode::PrintContentInLevel(int level) const {

	printf("%s\n", TypeUtils::GetTypeName(type));

}

/*        PRINT FUNCTION END        */

/*        AUXILIARY FUNCTION        */

/*      AUXILIARY FUNCTION END      */
#include <stdio.h>
#include "ConstantNode.h"

/*        CONSTRUCT FUNCTION        */

/*      CONSTRUCT FUNCTION END      */

/*         SEMANTIC ANALYZE         */

void ConstantNode::AnalyzeSemantic(SymbolTable *intab) {
	
}

/*       SEMANTIC ANALYZE END       */

/*         PRINT FUNCTION         */

void IntegerNode::PrintContentInLevel(int level) const {
	printf("[int] %d\n", num);
}

void FloatNode::PrintContentInLevel(int level) const {
	printf("[float] %f\n", num);
}

/*        PRINT FUNCTION END        */
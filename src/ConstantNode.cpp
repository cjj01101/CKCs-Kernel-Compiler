#include <stdio.h>
#include "ConstantNode.h"
#include "CodeGenerator.h"

/*      (DE)CONSTRUCT FUNCTION      */

/*    (DE)CONSTRUCT FUNCTION END    */

/*         SEMANTIC ANALYZE         */

void ConstantNode::AnalyzeSemantic(SymbolTable *intab) {
	
}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void IntegerNode::PrintContentInLevel(int level) const {
	printf("[int] %d\n", num);
}

void FloatNode::PrintContentInLevel(int level) const {
	printf("[float] %f\n", num);
}

/*        PRINT FUNCTION END        */

/*         GENERATE IR CODE         */

llvm::Value *IntegerNode::GenerateIR(CodeGenerator *generator) {
    return llvm::ConstantInt::get(generator->builder.getInt32Ty(), num);
}

llvm::Value *FloatNode::GenerateIR(CodeGenerator *generator) {
    return llvm::ConstantFP::get(generator->builder.getDoubleTy(), num);
}

/*       GENERATE IR CODE END       */

/*        AUXILIARY FUNCTION        */

/*      AUXILIARY FUNCTION END      */
#include <stdio.h>
#include "ConstantNode.h"
#include "SemanticAnalyzer.h"
#include "CodeGenerator.h"

/*      (DE)CONSTRUCT FUNCTION      */

/*    (DE)CONSTRUCT FUNCTION END    */

/*         SEMANTIC ANALYZE         */

void ConstantNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {
	
}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void IntegerNode::PrintContentInLevel(int level) const {
	printf("[int] %d\n", num);
}

void FloatNode::PrintContentInLevel(int level) const {
	printf("[float] %f\n", num);
}

void BooleanNode::PrintContentInLevel(int level) const {
	printf("[bool] %s\n", num ? "true" : "false");
}

/*        PRINT FUNCTION END        */

/*         GENERATE IR CODE         */

llvm::Value *IntegerNode::GenerateIR(CodeGenerator *generator) {
    return llvm::ConstantInt::get(generator->builder.getInt32Ty(), num);
}

llvm::Value *FloatNode::GenerateIR(CodeGenerator *generator) {
    return llvm::ConstantFP::get(generator->builder.getDoubleTy(), num);
}

llvm::Value *BooleanNode::GenerateIR(CodeGenerator *generator) {
    return llvm::ConstantInt::getBool(generator->builder.getInt1Ty(), num);
}

/*       GENERATE IR CODE END       */

/*        AUXILIARY FUNCTION        */

/*      AUXILIARY FUNCTION END      */
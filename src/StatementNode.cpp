#include <assert.h>
#include <stdio.h>
#include "ExpressionNode.h"
#include "DeclarationNode.h"
#include "StatementNode.h"
#include "Utility.h"
#include "SemanticAnalyzer.h"
#include "CodeGenerator.h"

using namespace TypeUtils;

/*      (DE)CONSTRUCT FUNCTION      */

ExpressionStatementNode::ExpressionStatementNode(ExpressionNode *exp)
	: StatementNode(), expression(exp)
{
	assert(NOT_NULL(exp));
}

ExpressionStatementNode::~ExpressionStatementNode() {
	delete expression;
}

IfStatementNode::IfStatementNode(ExpressionNode *condition, StatementNode *thenStmt, StatementNode *elseStmt)
	: StatementNode(), condition(condition), thenStmt(thenStmt), elseStmt(elseStmt)
{
	assert(NOT_NULL(condition));
	assert(NOT_NULL(thenStmt));
	assert(NOT_NULL(elseStmt));
}

IfStatementNode::~IfStatementNode() {
	delete condition;
	delete thenStmt;
	delete thenStmt;
}

WhileStatementNode::WhileStatementNode(ExpressionNode *condition, StatementNode *body)
	: StatementNode(), condition(condition), body(body)
{
	assert(NOT_NULL(condition));
	assert(NOT_NULL(body));
}

WhileStatementNode::~WhileStatementNode() {
	delete condition;
	delete body;
}

ForStatementNode::ForStatementNode(ASTNode *init, ExpressionNode *cond, ExpressionNode *loop, StatementNode *body)
	: StatementNode(), init(init), condition(cond), loop(loop), body(body)
{
	assert(NOT_NULL_OF_TYPE(init, ExpressionStatementNode*) || 
		   NOT_NULL_OF_TYPE(init, DeclarationNode*));
	assert(NOT_NULL(cond));
	assert(NOT_NULL(loop));
	assert(NOT_NULL(body));
}

ForStatementNode::~ForStatementNode() {
	delete init;
	delete condition;
	delete loop;
	delete body;
}

ReturnStatementNode::ReturnStatementNode(ExpressionNode *expression)
	: StatementNode(), expression(expression)
{
	assert(NOT_NULL(expression));
}

ReturnStatementNode::~ReturnStatementNode() {
	delete expression;
}

/*    (DE)CONSTRUCT FUNCTION END    */

/*         SEMANTIC ANALYZE         */

void ExpressionStatementNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {
	
	expression->AnalyzeSemantic(analyzer);
}

void CompoundStatementNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {
	
	analyzer->AddNewTable();
	for(auto item : items) item->AnalyzeSemantic(analyzer);
	analyzer->RemoveTable();

}

void IfStatementNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {
	
	condition->AnalyzeSemantic(analyzer);
	thenStmt->AnalyzeSemantic(analyzer);
	elseStmt->AnalyzeSemantic(analyzer);

	/* Verify Condition Expression Type */
	Type condType = condition->GetValueType();
	if(!CanConvert(condType, Type::BOOLEAN)) {
		throw ASTException("cannot convert '" + std::string(GetTypeName(condType)) + "' to 'BOOL'.");
	}

}

void WhileStatementNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {
		
	analyzer->EnterControlBlock();

	condition->AnalyzeSemantic(analyzer);
	body->AnalyzeSemantic(analyzer);

	/* Verify Condition Expression Type */
	Type condType = condition->GetValueType();
	if(!CanConvert(condType, Type::BOOLEAN)) {
		throw ASTException("cannot convert '" + std::string(GetTypeName(condType)) + "' to 'BOOL'.");
	}

	analyzer->LeaveControlBlock();

}

void ForStatementNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {
	
	analyzer->EnterControlBlock();
	analyzer->AddNewTable();

	init->AnalyzeSemantic(analyzer);
	condition->AnalyzeSemantic(analyzer);
	loop->AnalyzeSemantic(analyzer);
	body->AnalyzeSemantic(analyzer);

	/* Verify Condition Expression Type */
	if(!NOT_NULL_OF_TYPE(condition, EmptyExpressionNode*)) {
		Type condType = condition->GetValueType();
		if(!CanConvert(condType, Type::BOOLEAN)) {
			throw ASTException("cannot convert '" + std::string(GetTypeName(condType)) + "' to 'BOOL'.");
		}
	}

	analyzer->RemoveTable();
	analyzer->LeaveControlBlock();
}

void ReturnStatementNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {
	
	/* Check if in Function Scope */	
	if(!analyzer->IsInFunction()) {
		throw ASTException("expected function before ‘return’");
	}
	
	/* Analyze Return Expression */
	expression->AnalyzeSemantic(analyzer);

	/* Check Return Type */
	Type exprType = expression->GetValueType();
	Type returnType = analyzer->GetReturnType();
	if(!CanConvert(exprType, returnType)) {
		char message[128];
		sprintf(message, "return-statement of type '%s', in function returning ‘%s’.",
			GetTypeName(exprType), GetTypeName(returnType));
		throw ASTException(message);
	}
}

void BreakStatementNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {
	
	/* Check if in Loop or Switch */	
	if(!analyzer->IsInControlBlock()) {
		throw ASTException("break statement not within loop or switch.");
	}
}

void ContinueStatementNode::AnalyzeSemantic(SemanticAnalyzer *analyzer) {
	
	/* Check if in Loop or Switch */	
	if(!analyzer->IsInControlBlock()) {
		throw ASTException("continue statement not within loop or switch.");
	}
}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void ExpressionStatementNode::PrintContentInLevel(int level) const {
	if(NOT_NULL_OF_TYPE(expression, EmptyExpressionNode*)) {
		printf("Empty Statement\n");
	} else {
		printf("Expression Statement\n");

		PRINT_CHILD_WITH_HINT(expression, "EXPR");
	}
}

void CompoundStatementNode::PrintContentInLevel(int level) const {
	printf("Compound Statement\n");

	for(auto item : items) {
		PRINT_CHILD_WITH_HINT(item, "ITEM");
	}
}

void IfStatementNode::PrintContentInLevel(int level) const {
	printf("If Statement\n");

	PRINT_CHILD_WITH_HINT(condition, "COND");
	PRINT_CHILD_WITH_HINT(thenStmt, "THEN");
	PRINT_CHILD_WITH_HINT(elseStmt, "ELSE");
}

void WhileStatementNode::PrintContentInLevel(int level) const {
	printf("While Statement\n");

	PRINT_CHILD_WITH_HINT(condition, "WHILE");
	PRINT_CHILD_WITH_HINT(body, "THEN");
}

void ForStatementNode::PrintContentInLevel(int level) const {
	printf("For Statement\n");

	PRINT_CHILD_WITH_HINT(init, "INIT");
	PRINT_CHILD_WITH_HINT(condition, "COND");
	PRINT_CHILD_WITH_HINT(loop, "END OF LOOP");
	PRINT_CHILD_WITH_HINT(body, "BODY");
}

void ReturnStatementNode::PrintContentInLevel(int level) const {
	printf("Return Statement\n");

	if(NOT_NULL_OF_TYPE(expression, EmptyExpressionNode*)) return;
	
	PRINT_CHILD_WITH_HINT(expression, "RETURN VALUE");
}

void BreakStatementNode::PrintContentInLevel(int level) const {
	printf("Break Statement\n");
}

void ContinueStatementNode::PrintContentInLevel(int level) const {
	printf("Continue Statement\n");
}

/*        PRINT FUNCTION END        */

/*         GENERATE IR CODE         */

llvm::Value *CompoundStatementNode::GenerateIR(CodeGenerator *generator) {
    
    generator->AddNewTable();
    for (auto item : items) item->GenerateIR(generator);
    generator->RemoveTable();

    return nullptr;
}

llvm::Value *ExpressionStatementNode::GenerateIR(CodeGenerator *generator) {
    
    expression->GenerateIR(generator);

    return nullptr;
}

llvm::Value *IfStatementNode::GenerateIR(CodeGenerator *generator) {
    
    // Create Basic Blocks
    llvm::BasicBlock *thenBlock = generator->CreateBasicBlock("if-then");
    llvm::BasicBlock *elseBlock = generator->CreateBasicBlock("if-else");
    llvm::BasicBlock *afterBlock = generator->CreateBasicBlock("after-if");

    // Generate Condition Branch Instructions
    llvm::Value *condValue = condition->GenerateIR(generator);
    condValue = generator->CastValueType(condValue, condition->GetValueType(), Type::BOOLEAN);
    generator->builder.CreateCondBr(condValue, thenBlock, elseBlock);

    // Complete Then Block
    generator->JumpToBlock(thenBlock);
    thenStmt->GenerateIR(generator);
    generator->builder.CreateBr(afterBlock);

    // Complete Then Block
    generator->JumpToBlock(elseBlock);
    elseStmt->GenerateIR(generator);
    generator->builder.CreateBr(afterBlock);

    // Finish up
    generator->JumpToBlock(afterBlock);

    return nullptr;
}

llvm::Value *WhileStatementNode::GenerateIR(CodeGenerator *generator) {
    
    // Create Basic Blocks
    llvm::BasicBlock *condBlock = generator->CreateBasicBlock("whlie-cond");
    llvm::BasicBlock *loopBlock = generator->CreateBasicBlock("while-loop");
    llvm::BasicBlock *afterBlock = generator->CreateBasicBlock("after-while");

    // Record Blocks for Control Statement
    generator->PushLoopTargets(condBlock, afterBlock);

    // Complete Loop Condition Branch
    generator->JumpToBlock(condBlock);
    llvm::Value *condValue = condition->GenerateIR(generator);
    condValue = generator->CastValueType(condValue, condition->GetValueType(), Type::BOOLEAN);
    generator->builder.CreateCondBr(condValue, loopBlock, afterBlock);

    // Complete Loop Body
    generator->JumpToBlock(loopBlock);
    body->GenerateIR(generator);
    generator->builder.CreateBr(condBlock);

    // Finish up
    generator->PopLoopTargets();
    generator->JumpToBlock(afterBlock);

    return nullptr;
}

llvm::Value *ForStatementNode::GenerateIR(CodeGenerator *generator) {
    
    // Generate IR for Initial Statement
    generator->AddNewTable();
    init->GenerateIR(generator);

    // Create Basic Blocks
    llvm::BasicBlock *condBlock = generator->CreateBasicBlock("for-cond");
    llvm::BasicBlock *loopBlock = generator->CreateBasicBlock("for-loop");
    llvm::BasicBlock *afterBlock = generator->CreateBasicBlock("after-for");

    // Record Blocks for Control Statement
    generator->PushLoopTargets(condBlock, afterBlock);

    // Complete Loop Condition Branch
    generator->JumpToBlock(condBlock);
    llvm::Value *condValue = condition->GenerateIR(generator);
    if(!condValue) condValue = llvm::ConstantInt::getTrue(generator->builder.getInt1Ty()); // Empty Condition
    else condValue = generator->CastValueType(condValue, condition->GetValueType(), Type::BOOLEAN);
    generator->builder.CreateCondBr(condValue, loopBlock, afterBlock);

    // Complete Loop Body
    generator->JumpToBlock(loopBlock);
    body->GenerateIR(generator);
    generator->builder.CreateBr(condBlock);
    loop->GenerateIR(generator);

    // Finish up
    generator->PopLoopTargets();
    generator->RemoveTable();
    generator->JumpToBlock(afterBlock);

    return nullptr;
}

llvm::Value *ReturnStatementNode::GenerateIR(CodeGenerator *generator) {
    
    if(NOT_NULL_OF_TYPE(expression, EmptyExpressionNode*)) {
        generator->builder.CreateRetVoid();
    } else {
        generator->builder.CreateRet(expression->GenerateIR(generator));
    }

    return nullptr;
}

llvm::Value *BreakStatementNode::GenerateIR(CodeGenerator *generator) {
    
	generator->builder.CreateBr(generator->GetBreakTarget());

    return nullptr;
}

llvm::Value *ContinueStatementNode::GenerateIR(CodeGenerator *generator) {
    
	generator->builder.CreateBr(generator->GetContinueTarget());

    return nullptr;
}

/*       GENERATE IR CODE END       */

/*        AUXILIARY FUNCTION        */

void CompoundStatementNode::AppendStatement(ASTNode *item) {
	assert(NOT_NULL_OF_TYPE(item, StatementNode*) ||
		   NOT_NULL_OF_TYPE(item, DeclarationNode*));
	items.push_back(item);
}

/*      AUXILIARY FUNCTION END      */
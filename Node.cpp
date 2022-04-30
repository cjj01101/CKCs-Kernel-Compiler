#include <stdio.h>
#include <cstring>
#include "ASTNode.h"
#include "ValueNode.h"
#include "OperatorNode.h"
#include "StatementNode.h"

/*         PRINT FUNCTION         */

void ASTNode::PrintInLevel(int level) const {
	for(int i = 0; i < level; i++) {
		if(i == level - 1) printf("+-------");
		else printf("|       ");
	}
	PrintContentInLevel(level);
}

void IntegerNode::PrintContentInLevel(int level) const {
	printf("%d\n", num);
}

void VariableNode::PrintContentInLevel(int level) const {
	printf("[var]%s\n", id);
}

void ArithOpNode::PrintContentInLevel(int level) const {

	switch(op){
	case '+': printf("ADD\n"); break;
	case '-': printf("SUB\n"); break;
	case '*': printf("MUL\n"); break;
	case '/': printf("DIV\n"); break;
	case '%': printf("MOD\n"); break;
	}

	if(leftOperand) leftOperand->PrintInLevel(level + 1);
	if(rightOperand) rightOperand->PrintInLevel(level + 1);
}

void AssignOpNode::PrintContentInLevel(int level) const {
	printf("Assign\n");

	leftValue->PrintInLevel(level + 1);
	rightValue->PrintInLevel(level + 1);
}

void ExpressionStatementNode::PrintContentInLevel(int level) const {
	printf("Expression Statement\n");

	expression->PrintInLevel(level + 1);
}

/*        PRINT FUNCTION END        */

/*        CONSTRUCT FUNCTION        */

VariableNode::VariableNode(char *name) : ASTNode() {
	assert(name != NULL);
	strncpy(id, name, MAXVARLEN);
	id[MAXVARLEN-1] = '\0';
}

/*      CONSTRUCT FUNCTION END      */
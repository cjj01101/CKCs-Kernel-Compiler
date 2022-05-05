#include <assert.h>
#include <stdio.h>
#include <cstring>
#include "ExpressionNode.h"

/*        CONSTRUCT FUNCTION        */

IdentifierNode::IdentifierNode(char *name) : ExpressionNode() {
	assert(name != NULL);
	strncpy(id, name, MAXVARLEN);
	id[MAXVARLEN-1] = '\0';
}

/*      CONSTRUCT FUNCTION END      */

/*         SEMANTIC ANALYZE         */

void EmptyExpressionNode::AnalyzeSemantic(SymbolTable *intab) {
	valueType = Type::VOID;
}

void IdentifierNode::AnalyzeSemantic(SymbolTable *intab) {

	std::string sym = std::string(id);
	SymbolTable *occtab = intab->FindSymbolOccurrence(sym);
	if(occtab == nullptr) {
		throw ASTException("'" + sym + "' was not declared in this scope.");
	} else {
		valueType = occtab->entry.at(sym).type.type;
	}
	
}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void EmptyExpressionNode::PrintContentInLevel(int level) const {
	printf("Empty Expression\n");
}

void IdentifierNode::PrintContentInLevel(int level) const {
	printf("[ID] %s\n", id);
}

/*        PRINT FUNCTION END        */

/*        AUXILIARY FUNCTION        */

/*      AUXILIARY FUNCTION END      */
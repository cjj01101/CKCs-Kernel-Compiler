#include <assert.h>
#include <stdio.h>
#include "DeclarationNode.h"
#include "StatementNode.h"
#include "ExpressionNode.h"
#include "TypeNode.h"

/*      (DE)CONSTRUCT FUNCTION      */

DeclarationNode::DeclarationNode(IdentifierNode *name, TypeNode *type, ExpressionNode *init)
	: ASTNode(), name(name), type(type), initValue(init)
{
	assert(NOT_NULL(name));
	assert(NOT_NULL(type));
}

DeclarationNode::~DeclarationNode() {
	delete type;
	delete name;
	delete initValue;
}

/*    (DE)CONSTRUCT FUNCTION END    */

/*         SEMANTIC ANALYZE         */

void DeclarationNode::AnalyzeSemantic(SymbolTable *intab) {

	std::string sym(name->GetName());
	if(intab->HasSymbol(sym)) {
		throw ASTException("redeclaration of symbol '" + sym + "'.");
	}

	Type t = type->GetType();
	if(t == Type::VOID) {
		throw ASTException("variable or argument '" + sym + "' declared void.");
	}

	if(initValue) initValue->AnalyzeSemantic(intab);
	
	intab->AddEntry(sym, SymbolTableEntry(SymbolKind::VARIABLE, t));
}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void DeclarationNode::PrintContentInLevel(int level) const {
	printf("Declaration\n");

	PRINT_CHILD_WITH_HINT(type, "TYPE");
	PRINT_CHILD_WITH_HINT(name, "NAME");
	if(initValue) PRINT_CHILD_WITH_HINT(initValue, "INIT VALUE");
}

/*        PRINT FUNCTION END        */

/*        AUXILIARY FUNCTION        */

Type DeclarationNode::GetType() {
	return type->GetType();
}

char *DeclarationNode::GetName() {
	return name->GetName();
}

/*      AUXILIARY FUNCTION END      */
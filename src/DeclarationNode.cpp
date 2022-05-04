#include <assert.h>
#include <stdio.h>
#include "DeclarationNode.h"
#include "StatementNode.h"
#include "ExpressionNode.h"

/*      (DE)CONSTRUCT FUNCTION      */

DeclarationNode::DeclarationNode(IdentifierNode *name, TypeNode *type, ASTNode *init)
	: ASTNode(), name(name), type(type), initValue(init)
{
	assert(NOT_NULL(name));
	assert(NOT_NULL(type));
	assert(NULLABLE_OF_TYPE(init, ExpressionNode*));
}

DeclarationNode::~DeclarationNode() {
	delete type;
	delete name;
	delete initValue;
}

/*    (DE)CONSTRUCT FUNCTION END    */

/*         SEMANTIC ANALYZE         */

void DeclarationNode::AnalyzeSemantic(SymbolTable *intab) {
	
	std::string sym = std::string(name->GetName());
	if(intab->HasSymbol(sym)) {
		throw ASTException("Redeclaration of symbol '" + sym + "'.");
	}
	
	intab->AddEntry(sym, SymbolTableEntry(SymbolKind::variable, type->GetType()));
}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void DeclarationNode::PrintContentInLevel(int level) const {
	printf("Declaration\n");

	PRINT_CHILD_WITH_HINT(type, "TYPE");
	PRINT_CHILD_WITH_HINT(name, "NAME");
	if(initValue) PRINT_CHILD_WITH_HINT(initValue, "INIT VALUE");
}

void TypeNode::PrintContentInLevel(int level) const {

	const static char *typeName[] = {
		#define TYPE(type) #type,
		TYPES
		#undef TYPE
	};

	printf("%s\n", typeName[static_cast<int>(type)]);

}

/*        PRINT FUNCTION END        */

/*        AUXILIARY FUNCTION        */

/*      AUXILIARY FUNCTION END      */
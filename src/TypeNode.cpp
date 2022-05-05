#include "TypeNode.h"

/*         SEMANTIC ANALYZE         */

void TypeNode::AnalyzeSemantic(SymbolTable *intab) {
	
}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void TypeNode::PrintContentInLevel(int level) const {

	printf("%s\n", GetTypeName(type));

}

/*        PRINT FUNCTION END        */

/*        AUXILIARY FUNCTION        */

const char *TypeNode::GetTypeName(Type type) {

	const static char *typeName[] = {
		#define TYPE(type) #type,
		TYPES
		#undef TYPE
	};

	return typeName[static_cast<int>(type)];
}

bool TypeNode::IsTypeCompatible(Type first, Type second){

	if(first == Type::VOID && second != Type::VOID) return false;
	if(first != Type::VOID && second == Type::VOID) return false;
	return true;
	
}

Type TypeNode::GetPromotedTypeBetween(Type first, Type second) {

	if(!IsTypeCompatible(first, second)) return Type::VOID;

	if(first == Type::FLOAT || second == Type::FLOAT) {
		return Type::FLOAT;
	} else if(first == Type::INTEGER || second == Type::INTEGER) {
		return Type::INTEGER;
	} else {
		return Type::VOID;
	}
}

/*      AUXILIARY FUNCTION END      */
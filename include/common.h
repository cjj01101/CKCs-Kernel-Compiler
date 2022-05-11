#ifndef _COMMON_H_
#define _COMMON_H_

/* FORWARD DECLARATION */
class ASTNode;
class TypeNode;
class IdentifierNode;
class ParameterListNode;
class ArgumentListNode;
class DeclaratorListNode;
class ExpressionNode;
class StatementNode;
class CompoundStatementNode;
class DeclarationNode;
class TranslationUnitNode;
/* FORWARD DECLARATION */

#define MAXVARLEN 64

#define TYPES \
	TYPE(INTEGER) TYPE(FLOAT) TYPE(BOOLEAN) TYPE(VOID)

#define OPERATORS \
	OP(COM) \
	OP(LOGOR) OP(LOGAND) \
	OP(OR) OP(XOR) OP(AND) \
	OP(EQ) OP(NEQ) \
	OP(LT) OP(LTE) OP(GT) OP(GTE) \
	OP(SHL) OP(SHR) \
	OP(ADD) OP(SUB) OP(MUL) OP(DIV) OP(MOD)

enum class Type : unsigned char {
	#define TYPE(type) type,
	TYPES
	#undef TYPE
};

enum class Operator : unsigned char {
	#define OP(op) op,
	OPERATORS
	#undef OP
};

#endif
#ifndef _COMMON_H_
#define _COMMON_H_

#define MAXVARLEN 64

#define OPERATORS \
	OP(LOGOR) OP(LOGAND) \
	OP(OR) OP(XOR) OP(AND) \
	OP(EQ) OP(NEQ) \
	OP(LT) OP(LTE) OP(GT) OP(GTE) \
	OP(ADD) OP(SUB) OP(MUL) OP(DIV) OP(MOD)

enum class Type : unsigned char {
	INTEGER = 1,
};

enum class Operator : unsigned char {
	#define OP(op) op,
	OPERATORS
	#undef OP
};

#endif
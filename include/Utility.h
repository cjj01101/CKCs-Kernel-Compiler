#ifndef _TYPE_UTILS_H_
#define _TYPE_UTILS_H_

#include "common.h"

namespace TypeUtils {

	const char *GetTypeName(Type type);
	bool IsIntegerType(Type type);
	bool IsArithmeticType(Type type);
	bool CanConvert(Type from, Type to);
	bool IsCompatible(Type first, Type second);
	Type PromoteArithmeticType(Type first, Type second);

}

namespace OperatorUtils {

	const char *GetOperatorName(Operator op);

}

#endif
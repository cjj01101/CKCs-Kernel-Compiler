#include <assert.h>
#include "Utility.h"

namespace TypeUtils {

	const char *GetTypeName(Type type) {

		const static char *typeName[] = {
			#define TYPE(type) #type,
			TYPES
			#undef TYPE
		};

		return typeName[static_cast<int>(type)];
	}

	bool CanConvert(Type from, Type to) {

		if(from == Type::VOID && to != Type::VOID) return false;
		if(from != Type::VOID && to == Type::VOID) return false;
		return true;
		
	}

	bool IsCompatible(Type first, Type second) {
		return CanConvert(first, second) || CanConvert(second, first);
	}

	bool IsIntegerType(Type type) {
		return (type == Type::INTEGER || type == Type::BOOLEAN);
	}

	bool IsArithmeticType(Type type) {
		return (IsIntegerType(type) || type == Type::FLOAT);
	}

	Type PromoteArithmeticType(Type first, Type second) {

		assert(IsArithmeticType(first) && IsArithmeticType(second));

		if(first == Type::FLOAT || second == Type::FLOAT) {
			return Type::FLOAT;
		} else if(first == Type::INTEGER || second == Type::INTEGER) {
			return Type::INTEGER;
		} else if(first == Type::BOOLEAN || second == Type::BOOLEAN) {
			return Type::BOOLEAN;
		} else {
			return Type::VOID;
		}
	}

}

namespace OperatorUtils {

	const char *GetOperatorName(Operator op) {

		const static char *operatorName[] = {
			#define OP(op) #op,
			OPERATORS
			#undef OP
		};

		return operatorName[static_cast<int>(op)];

	}

}
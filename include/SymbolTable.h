 #ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#include <unordered_map>
#include <vector>
#include <string>
#include "common.h"

enum class SymbolKind {
	FUNCTION, VARIABLE
};

struct SymbolType {

	SymbolType(Type type) : type(type), argTypes() {}
	SymbolType(Type type, const std::vector<Type> &argTypes) : type(type), argTypes(argTypes) { }
	SymbolType(const SymbolType &rhs) : type(rhs.type), argTypes(rhs.argTypes) { }
	~SymbolType() {}

	Type type;
	std::vector<Type> argTypes; // Ignore if not function kind
};

struct SymbolTableEntry {

	SymbolTableEntry(SymbolKind kind, const SymbolType &type) : kind(kind), type(type) {}
	~SymbolTableEntry() {}

	SymbolKind kind;
	SymbolType type;
};

using SymbolTable = std::unordered_map<std::string, SymbolTableEntry>;

#endif
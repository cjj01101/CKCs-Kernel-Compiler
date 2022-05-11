#ifndef _SEMANTIC_ANALYZER_H_
#define _SEMANTIC_ANALYZER_H_

#include "SymbolTable.h"

class SemanticAnalyzer {

public:
	using TablePointer = std::vector<SymbolTable>::reverse_iterator;

	SemanticAnalyzer() : tables(), controlBlockNestedLevel(0), inFunction(false), returnType(Type::VOID) {}
	~SemanticAnalyzer() {}

	SymbolTable &GetCurrentTable() { return tables.back(); }
	void AddNewTable() { tables.push_back(SymbolTable()); }
	void RemoveTable() { tables.pop_back(); }
	void AddSymbol(const std::string &sym, const SymbolTableEntry &content)
		{ GetCurrentTable().insert({sym, content}); }

	bool HasSymbol(const std::string &sym);
	TablePointer FindSymbolOccurrence(const std::string &sym);
	TablePointer NoTable() { return tables.rend(); }

	void EnterControlBlock() { controlBlockNestedLevel++; }
	void LeaveControlBlock() { controlBlockNestedLevel--; }
	bool IsInControlBlock() { return controlBlockNestedLevel > 0; }

	void EnterFunction(Type returnType) { inFunction = true; this->returnType = returnType; }
	void LeaveFunction() { inFunction = false; }
	bool IsInFunction() { return inFunction; }
	Type GetReturnType()  { return returnType; }

private:

	std::vector<SymbolTable> tables;

	int controlBlockNestedLevel;

	bool inFunction;
	Type returnType;

};

#endif
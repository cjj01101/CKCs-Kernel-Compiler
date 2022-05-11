#ifndef _SEMANTIC_ANALYZER_H_
#define _SEMANTIC_ANALYZER_H_

#include "SymbolTable.h"

class SemanticAnalyzer {

public:
	using TablePointer = std::vector<SymbolTable>::reverse_iterator;

	SemanticAnalyzer() : tables() {}
	~SemanticAnalyzer() {}

	SymbolTable &GetCurrentTable() { return tables.back(); }
	void AddNewTable() { tables.push_back(SymbolTable()); }
	void RemoveTable() { tables.pop_back(); }
	void AddSymbol(const std::string &sym, const SymbolTableEntry &content)
		{ GetCurrentTable().insert({sym, content}); }

	bool HasSymbol(const std::string &sym);
	TablePointer FindSymbolOccurrence(const std::string &sym);
	TablePointer NoTable() { return tables.rend(); }

private:

	std::vector<SymbolTable> tables;

};

#endif
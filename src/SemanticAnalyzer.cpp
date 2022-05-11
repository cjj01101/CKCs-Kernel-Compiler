#include "SemanticAnalyzer.h"

bool SemanticAnalyzer::HasSymbol(const std::string &sym) {
	const SymbolTable &table = GetCurrentTable();
	return (table.find(sym) != table.end());
}

SemanticAnalyzer::TablePointer SemanticAnalyzer::FindSymbolOccurrence(const std::string &sym){
	for(auto it = tables.rbegin(); it != tables.rend(); it++) {
	    if(it->find(sym) != it->end()) return it;
	}
	return tables.rend();
}
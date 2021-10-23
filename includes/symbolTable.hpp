#ifndef SYMBOLTABLE_HPP_
#define SYMBOLTABLE_HPP_

#include <string>
#include <unordered_map>

class SymbolTable {
    std::unordered_map<std::string, int> symbols;
    int nextAvailableAddress;

public:
    SymbolTable();

    // Adds a (symbol, address) pair to the symbol table. Used for labels.
    void addSymbol(std::string symbol, int address);

    // Adds a (symbol, address) pair to the symbol table. Used for variables.
    void addVariable(std::string);

    // Check if symbol exists in the symbol table.
    bool contains(std::string symbol);

    // Lookup the RAM address for the given symbol.
    int getAddress(std::string symbol);
};
#endif //SYMBOLTABLE_HPP_

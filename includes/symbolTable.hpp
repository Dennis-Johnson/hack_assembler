#pragma once

#include <string>
#include <unordered_map>

class SymbolTable {
    std::unordered_map<std::string, int> symbols;
    int nextAvailableAddress;

public:
    SymbolTable();

    // Adds a symbol to the table at the given address.
    void addSymbol(const std::string symbol, const int address);

    // Adds a symbol to the table at nextAvailableAddress
    void addSymbol(const std::string);

    // Check if symbol exists in the symbol table.
    bool contains(const std::string symbol);

    // Lookup the RAM address for the given symbol.
    int getAddress(const std::string symbol);
};

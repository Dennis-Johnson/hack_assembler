/*
symbolTable.cpp

Used to store symbols during translation.
A symbol can be predefined, a variable, or a label.
*/

#include "../includes/symbolTable.hpp"
#include "../includes/util.hpp"
#include <iostream>
#include <string>
#include <utility>

SymbolTable::SymbolTable(){
    // Add predefined symbols
    symbols.insert({{"SP", 0}, {"LCL", 1}, {"ARG", 2}, {"THIS", 3}, {"THAT", 4},
                    {"R0", 0}, {"R1", 1}, {"R2", 2}, {"R3", 3}, {"R4", 4},
                    {"R5", 5}, {"R6", 6}, {"R7", 7}, {"R8", 8}, {"R9", 9},
                    {"R10", 10}, {"R11", 11}, {"R12", 12}, {"R13", 13}, {"R14", 14},
                    {"R15", 15}, {"SCREEN", 16384}, {"KBD", 24576}});

    // Next available RAM address after the predefined symbols.
    nextAvailableAddress = 16;
}

void SymbolTable::addSymbol(const std::string symbol, const int address){
    assertm(nextAvailableAddress < 16384, "Symbol Table is full");
    symbols.insert({symbol, address});
}

void SymbolTable::addSymbol(const std::string symbol){
    assertm(nextAvailableAddress < 16384, "Symbol Table is full");
    symbols.insert({symbol, nextAvailableAddress});
    nextAvailableAddress++;
}

bool SymbolTable::contains(const std::string symbol){
    return symbols.contains(symbol);
}

int SymbolTable::getAddress(const std::string symbol){
    return symbols[symbol];
}

void SymbolTable::displayTable() {
    for (auto const &pair: symbols) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}
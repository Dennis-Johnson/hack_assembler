#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "symbolTable.hpp"

class Parser {
    std::vector<std::string> inputLines;
    int currentLineNumber;
    SymbolTable symbolTable;
    
public:
    Parser(std::string filePath);
};
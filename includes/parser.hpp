#ifndef PARSER_HPP_
#define PARSER_HPP_

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

#endif //PARSER_HPP_
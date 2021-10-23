/*
parser.hpp

A simple parser that translates line by line.
*/

#pragma once
#include "symbolTable.hpp"
#include "instruction.hpp"
#include <iostream>
#include <string>
#include <variant>
#include <vector>

class Parser {
    std::vector<std::string> inputLines;
    std::string getStrippedLine(int lineNumber);
    int currentLineNumber;
    SymbolTable symbolTable;

public:
    Parser(std::string filePath);
    std::variant<AInstruction, CInstruction> getNextCommand();
    bool hasMoreCommands();
    void addLabels();
};
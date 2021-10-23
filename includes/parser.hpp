#pragma once
#include "symbolTable.hpp"
#include "instruction.hpp"
#include <iostream>
#include <string>
#include <variant>
#include <vector>

class Parser {
    std::vector<std::string> inputLines;

    int currentLineNumber;
    SymbolTable symbolTable;
    std::string getStrippedLine(int lineNumber);

public:
    Parser(std::string filePath);
    bool hasMoreCommands();
    std::variant<AInstruction, CInstruction> getNextCommand();
    void addLabels();
};
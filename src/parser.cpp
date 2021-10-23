#include "../includes/parser.hpp"
#include "../includes/symbolTable.hpp"
#include "../includes/util.hpp"
#include <string>
#include <iostream>
#include <fstream>

Parser::Parser(std::string filePath){
    std::fstream inputFile;
    inputFile.open(filePath, std::ios::in);

    // Read contents into a buffer
    if (inputFile.is_open()){
        std::string line;

        while(getline(inputFile, line)){
            inputLines.push_back(line);
        }
        inputFile.close();
    }
    currentLineNumber = 0;
    symbolTable = SymbolTable();

    // First pass to add just labels to symbol table.
    addLabels();
}

bool Parser::hasMoreCommands (){
    return currentLineNumber < inputLines.size();
}

Instruction Parser::getNextCommand(){
    Instruction instr;

    std::string line;
    // Skip over lines with only whitespace, comments, or labels.
    while((line = getStrippedLine(currentLineNumber)) == "")
        currentLineNumber++;

    // This is an A instruction.
    if (line.front() == '@'){
        if (isdigit(line.at(1))){
            instr = AInstruction(line.substr(1));
        }

        // This is a symbol
        else{
            std::string symbolName = line.substr(1);
            if(!symbolTable.contains(symbolName))
                symbolTable.addSymbol(symbolName);

            instr = AInstruction("@" + std::to_string(symbolTable.getAddress(symbolName)));
        }
    }

    // This is a C instruction.
    else
        instr = CInstruction(line);

    currentLineNumber++;
    return instr;
}

// Strips a line of comments and whitespace and returns it.
std::string Parser::getStrippedLine(int lineNumber){
    std::string& line = inputLines[lineNumber];
    line = Util::strip(line);

    // Strip comments if found.
    size_t commentStart = line.find("//");
    if (commentStart != line.npos)
        line = Util::strip(line.substr(0, commentStart));

    // Clears line if it's a label
    if (line.front() == '(' && line.back() == ')')
        line = "";
    
    return line;
}

// For first pass where all labels and their addresses are identified. No translation yet.
void Parser::addLabels() {
    int lineNumber = 0;
    assertm(inputLines.size() > 0, "No lines to parse.");

    for(std::string line: inputLines){
        line = Util::strip(line);

        // Skip lines with only whitespace or comments
        if (line.size() == 0 || line.substr(0, 2) == "//")
            continue;

        // Add this label to the symbol table.
        else if (line.front() == '(' && line.back() == ')') {
            // Remove the parentheses from the line to get the label name.
            std::string symbolName = line.substr(1, line.size() - 2);

            assertm(!symbolTable.contains(symbolName), "This label is already defined.");
            symbolTable.addSymbol(symbolName, lineNumber);
        }

        // Increment counter when you find an A or C instruction.
        else
            lineNumber++;
    }
}
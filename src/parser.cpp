#include "../includes/parser.hpp"
#include "../includes/symbolTable.hpp"
#include <string>
#include <iostream>

Parser::Parser(std::string filePath){
    std::cout << "Parser setup\n";

    symbolTable = SymbolTable();
}
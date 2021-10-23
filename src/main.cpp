#include "../includes/parser.hpp"
#include <iostream>
#include <variant>
#include <fstream>
#include <filesystem>

int main(int argc, char* argv[]) {
    std::string fileName;
    if (argc == 2){
        // Get filename
        fileName = std::filesystem::path(argv[1]).stem();
        std::cout << "INFO: Translating file: " << fileName << std::endl;
    }
    else {
        std::cerr << "ERROR: Incorrect usage, expected a .hack file." << std::endl;
    }

    Parser parser = Parser(argv[1]);
    std::vector<std::string> translatedLines;

    while (parser.hasMoreCommands())
    {
        auto instrVariant = parser.getNextCommand();
        
        // Check if it's an A or C instruction. 
        if (std::holds_alternative<AInstruction>(instrVariant)){
            auto instr = std::get < AInstruction > (instrVariant);
            translatedLines.push_back(instr.getBinaryTranslation());
        }

        else if (std::holds_alternative<CInstruction>(instrVariant)){
            auto instr = std::get < CInstruction > (instrVariant);
            translatedLines.push_back(instr.getBinaryTranslation());
        }
    }

    // Write to <fileName>.hack file
    std::ofstream outFile;
    outFile.open("generated/" + fileName + ".hack", std::ios::out);
    
    if(outFile.is_open()){
        for (auto line: translatedLines)
            outFile << line << "\n";

        std::cout << "Success --> generated/" + fileName + ".hack created" << std::endl;
    }
    else
        std::cerr << "Couldn't write to output file." << std::endl;
    outFile.close();

    return 0;
}
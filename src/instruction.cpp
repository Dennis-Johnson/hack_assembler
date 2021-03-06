/*
instruction.cpp

Implemented an instruction in Hack Assembly.
*/

#include "../includes/instruction.hpp"
#include "../includes/hackSpec.hpp"
#include "../includes/util.hpp"
#include <string>
#include <bitset>
#include <cctype>

// Addressing Instruction implementations
AInstruction::AInstruction(){}
AInstruction::AInstruction(std::string line){
    // Ignore the leading '@' sign in the A instruction.
    value = stoi(line.substr(1));
}

std::string AInstruction::getBinaryTranslation(){
    // Return a 16-bit binary string.
    return std::bitset<16>(value).to_string();
}

// Compute Instruction implementations
CInstruction::CInstruction(){}
CInstruction::CInstruction(std::string line)
{
    size_t found = line.find("=");
    if (found == std::string::npos){
        // Dest field is null, only comp and jump fields.
        dest = "null";

        size_t indx = line.find(';');
        comp = Util::strip(line.substr(0, indx));
        jump = Util::strip(line.substr(indx + 1));
    }

    else {
        // Jump field is null, only comp and dest fields.
        jump = "null";

        size_t indx = line.find('=');
        dest = Util::strip(line.substr(0, indx));
        comp = Util::strip(line.substr(indx + 1));
    }
}

std::string CInstruction::getBinaryTranslation(){
    // Initial 1 is the opCode for C instruction. The remaining '11' are ignored bits. Concat the rest.
    return "111" + HackSpec::translateCompField(comp) + HackSpec::translateDestField(dest) + HackSpec::translateJumpField(jump);
}

#include "../includes/instruction.hpp"
#include "../includes/hackSpec.hpp"
#include <string>
#include <bitset>
#include <cctype>

std::string strip(const std::string &inpt)
{
    auto start_it = inpt.begin();
    auto end_it = inpt.rbegin();
    while (std::isspace(*start_it))
        ++start_it;
    while (std::isspace(*end_it))
        ++end_it;
    return std::string(start_it, end_it.base());
}

AInstruction::AInstruction(std::string line){
    // Ignore the leading '@' sign in the A instruction.
    value = stoi(line.substr(1));
}

std::string AInstruction::getBinaryTranslation(){
    // Return a 16-bit binary string.
    return std::bitset<16>(value).to_string();
}

CInstruction::CInstruction(std::string line){
    size_t found = line.find("=");
    if (found != std::string::npos){
        // Dest field is null, only comp and jump fields.
        dest = "null";

        size_t indx = line.find(';');
        comp = strip(line.substr(0, indx));
        jump = strip(line.substr(indx));
    }

    // Jump field is null, only comp and dest fields.
    else {
        jump = "null";

        size_t indx = line.find('=');
        dest = strip(line.substr(0, indx));
        comp = strip(line.substr(indx));
    }
}

std::string CInstruction::getBinaryTranslation(){
    return "111" + HackSpec::translateCompField(comp) + HackSpec::translateDestField(dest) + HackSpec::translateJumpField(jump);
}

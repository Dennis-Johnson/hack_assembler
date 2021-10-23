/*
HackSpec.cpp

Utilities to lookup binary values for mnemonics in the Hack Assembly specification.
*/

#include "../includes/hackSpec.hpp"
#include <string>
#include <stdexcept>

namespace HackSpec{
    std::string translateDestField(std::string destKey){
        if (destField.contains(destKey))
            return destField[destKey];
        throw std::invalid_argument("The dest mnemonic is invalid.");
    }

    std::string translateCompField(std::string compKey){
        if (compField.contains(compKey))
            return compField[compKey];
        throw std::invalid_argument("The comp mnemonic is invalid.");
    }
    std::string translateJumpField(std::string jumpKey){
        if (jumpField.contains(jumpKey))
            return compField[jumpKey];
        throw std::invalid_argument("The jump mnemonic is invalid.");
    }
}
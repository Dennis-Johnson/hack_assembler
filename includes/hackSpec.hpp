/*
HackSpec.hpp

Utilities for binary translations of mnemonics used in the C-instruction of Hack Assembly language.
*/

#pragma once
#include <unordered_map>
#include <string>

namespace HackSpec {
    // Lookup dest field bits with format d1-d2-d3
    extern std::unordered_map<std::string, std::string> destField;

    // Lookup comp field bits with format a-c-c-c-c-c-c
    extern std::unordered_map<std::string, std::string> compField;

    // Lookup jump field bits with format j1-j2-j3
    extern std::unordered_map<std::string, std::string> jumpField;

    // Utilities to lookup mnemonics to get binary string representations.
    std::string translateDestField(std::string destKey);
    std::string translateCompField(std::string compKey);
    std::string translateJumpField(std::string jumpKey);
}
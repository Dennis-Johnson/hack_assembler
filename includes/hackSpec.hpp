/*
HackSpec.hpp

Define binary translations of mnemonics used in the C-instruction of Hack Assembly language.
*/
#pragma once
#include <unordered_map>
#include <string>

namespace HackSpec {
    // Lookup destination field bits with format d1-d2-d3
    std::unordered_map<std::string, std::string> destField = {
        {"null", "000"}, {"M", "001"}, {"D", "010"}, {"MD", "011"},
        {"A", "100"}, {"AM", "101"}, {"AD", "110"}, {"AMD", "111"},
    };

    // Lookup comp field bits with format a-c-c-c-c-c-c
    std::unordered_map<std::string, std::string> compField = {
        {"0",  "0101010"}, {"1",  "0111111"}, {"-1", "0111010"}, {"D",  "0001100"}, {"A",  "0110000"}, {"M",  "1110000"},
        {"!D", "0001101"}, {"!A", "0110001"}, {"!M", "1110001"}, {"-D", "0001111"}, {"-A", "0110011"}, {"-M", "1110011"},
        {"D+1", "0011111"}, {"A+1", "0110111"}, {"M+1", "1110111"}, {"D-1", "0001110"}, {"A-1", "0110010"}, {"M-1", "1110010"},
        {"D+A", "0000010"}, {"D+M", "1000010"}, {"D-A", "0010011"}, {"D-M", "1010011"}, {"A-D", "0000111"},  {"M-D", "1000111"},
        {"D&A", "0000000"}, {"D&M", "1000000"}, {"D|A", "0010101"}, {"D|M", "1010101"},
    };

    // Lookup jump field bits with format j1-j2-j3
    std::unordered_map<std::string, std::string> jumpField = {
        {"null","000"}, {"JGT","001"}, {"JEQ","010"}, {"JGE","011"},
        {"JLT","100"}, {"JNE","101"}, {"JLE","110"}, {"JMP","111"},
    };

    // Utilities to lookup mnemonics to obtain binary string representations.
    std::string translateDestField(std::string destKey);
    std::string translateCompField(std::string compKey);
    std::string translateJumpField(std::string jumpKey);
}
/*
instruction.hpp

Defines an instruction in Hack Assembly.
*/

#pragma once
#include <string>

// Base class for an instruction.
class Instruction {
    public:
        std::string getBinaryTranslation();
};

class AInstruction : public Instruction {
    int value;
public:
    AInstruction(std::string line);
    std::string getBinaryTranslation();
};

class CInstruction : public Instruction {
    std::string dest;
    std::string comp;
    std::string jump;

public:
    CInstruction(std::string line);
    std::string getBinaryTranslation();
};
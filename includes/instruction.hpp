/*
instruction.hpp

Defines an instruction in Hack Assembly.
*/

#pragma once
#include <string>

// Absrtact base class for an instruction.
class Instruction {
    public:
        virtual std::string getBinaryTranslation() = 0;
};

// Addressing Instruction
class AInstruction : public Instruction {
    int value;

public:
    AInstruction();
    AInstruction(std::string line);
    std::string getBinaryTranslation();
};

// Compute Instruction
class CInstruction : public Instruction {
    std::string dest;
    std::string comp;
    std::string jump;

public:
    CInstruction();
    CInstruction(std::string line);
    std::string getBinaryTranslation();
};
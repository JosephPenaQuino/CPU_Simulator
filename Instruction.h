#ifndef CPU_SIMULATOR_INSTRUCTION_H
#define CPU_SIMULATOR_INSTRUCTION_H

#include <cstdint>
#include <cmath>
//#include "CPU.h"

class CPU;

struct CompR
{
    uint32_t Rs : 5;
    uint32_t Rt : 5;
    uint32_t Rd : 5;
    uint32_t SA : 5;
    uint32_t funct_code : 6;
};

struct CompI
{
    uint32_t Rs : 5;
    uint32_t Rt : 5;
    uint32_t comp_const : 16;
};

struct CompJ
{
    uint32_t jump_target : 26;
};

union complement
{
    CompR comp_r;
    CompI comp_i;
    CompJ comp_j;
};

class Instruction
{
private:
    uint32_t op_code : 6;

protected:
    complement comp;

public:
    Instruction() = default;
    explicit Instruction(uint32_t op_code);
    virtual void apply(CPU &my_cpu);
    virtual char type();
};



#endif
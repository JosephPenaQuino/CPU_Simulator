#ifndef CPU_SIMULATOR_INSTRUCTION_H
#define CPU_SIMULATOR_INSTRUCTION_H

#include <cstdint>
#include <cmath>

#include "CPU.h"

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
    explicit Instruction(uint32_t op_code);
    virtual void apply(CPU &my_cpu);
    virtual char type();
};

class Instruction_R: public Instruction
{
private:

public:
    Instruction_R(uint32_t op_code, uint32_t Rs, uint32_t Rt, uint32_t Rd, uint32_t SA, uint32_t Funct_code);
    char type() override ;
};

class Instruction_I : public Instruction
{
private:

public:
    Instruction_I(uint32_t op_code, uint32_t Rs, uint32_t Rt, uint32_t comp_const);
    char type() override;
};

class Instruction_J : public Instruction
{
private:

public:
    Instruction_J(uint32_t op_code, uint32_t jump_target);
    char type() override ;
};

class Instruction_add : public Instruction_R
{
public:
    Instruction_add(uint32_t Rs, uint32_t Rt, uint32_t Rd);
    void apply(CPU &my_cpu) override;
};

class Instruction_sw : public Instruction_I
{
public:
    Instruction_sw(uint32_t Rs, uint32_t Rt, uint32_t offset);
    void apply(CPU &my_cpu) override;
};

class Instruction_lw : public Instruction_I
{
public:
    Instruction_lw(uint32_t Rs, uint32_t Rt, uint32_t offset);
    void apply(CPU &my_cpu) override;
};

#endif


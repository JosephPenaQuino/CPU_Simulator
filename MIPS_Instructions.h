#ifndef CPU_SIMULATOR_MIPS_INSTRUCTIONS_H
#define CPU_SIMULATOR_MIPS_INSTRUCTIONS_H

#include "Instruction.h"
#include "CPU.h"

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

class Instruction_lui : public Instruction_I
{
public:
    Instruction_lui(uint32_t Rt, uint32_t immediate);
    void apply(CPU &my_cpu) override;
};

class Instruction_ori: public Instruction_I
{
public:
    Instruction_ori(uint32_t Rs, uint32_t Rt, uint32_t immediate);
    void apply(CPU &my_cpu) override;
};

class Instruction_nop: public Instruction_R
{
public:
    Instruction_nop();
    void apply(CPU &my_cpu) override;
};

#endif //CPU_SIMULATOR_MIPS_INSTRUCTIONS_H

#ifndef CPU_SIMULATOR_CPU_H
#define CPU_SIMULATOR_CPU_H

#include <string>
#include "HardwareBlock.h"
#include "Instruction.h"
#include "read_write_mem.h"
#include "read_mem.h"

#define CPUId 1

struct CPU_state
{
    bool error;
    bool any_change;

    CPU_state();
};

class CPU : public HardwareBlock
{
private:
    int data_mem_size;
    int prog_mem_size;

    read_write_mem<int> data_mem;
    read_mem<Instruction> prog_mem;

    int program_counter;

public:
    CPU(int data_memory_size, int program_memory_size);
    int data_reg(int reg);
    int get_id(std::string reg);
    int get_data_mem_size();
    int get_prog_mem_size();
    CPU_state execute_instruction();
    Instruction get_instr();

};

#endif //CPU_SIMULATOR_CPU_H

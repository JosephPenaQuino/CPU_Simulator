#include "CPU.h"


int CPU::get_id(std::string reg)
{
    return 0;
}

int CPU::get_data_mem_size()
{
    return data_mem_size;
}

int CPU::get_prog_mem_size()
{
    return prog_mem_size;
}

CPU::CPU(int data_memory_size, int program_memory_size) : data_mem_size{data_memory_size}, prog_mem_size{program_memory_size}, program_counter{0}
{
    data_mem = new int[data_memory_size];
    prog_mem = new int[program_memory_size];
}

int CPU::data_reg(int reg)
{
    return 0;
}

bool CPU::execute_instruction()
{
    return false;
}
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

CPU::CPU(int data_memory_size, int program_memory_size) :   data_mem_size{data_memory_size},
                                                            prog_mem_size{program_memory_size},
                                                            program_counter{0},
                                                            prog_mem{read_mem<Instruction>(program_memory_size)},
                                                            data_mem{read_write_mem<int>(data_memory_size)} {}

int CPU::data_reg(int reg)
{
    return 0;
}

CPU_state CPU::execute_instruction()
{
    Instruction current_instruction = this->get_instr();
    current_instruction.apply(this);
    return CPU_state();
}

Instruction CPU::get_instr() {
    Instruction instr = prog_mem.get_instructions(program_counter);
    program_counter++;
    return instr;
}

CPU_state::CPU_state() : error{true}, any_change{false} {}

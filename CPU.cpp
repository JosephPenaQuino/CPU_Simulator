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
                                                            prog_mem{read_mem<Instruction*>(program_memory_size)},
                                                            data_mem{read_write_mem<int>(data_memory_size)},
                                                            reg_file{0} {}

int CPU::data_reg(int reg)
{
    return 0;
}

CPU_state CPU::execute_instruction()
{
    Instruction * current_instruction = this->get_instr();
    current_instruction->apply(*this);
    CPU_state my_result;
    my_result.error = false;
    my_result.any_change = false;
    return my_result;
}

Instruction * CPU::get_instr()
{
    if (program_counter >= prog_mem_size)
        program_counter = 0;
    Instruction * instr = prog_mem.get_instructions(program_counter);
    return instr;
}

void CPU::print_data_memory()
{
    for (int i = 0; i < data_mem_size; ++i)
    {
        std::cout << i << ":\t" << data_mem.load_value(i) << std::endl;
    }
}

uint32_t CPU::get_data(uint32_t address)
{
    return data_mem.load_value(address);
}

void CPU::set_data(uint32_t address, uint32_t value)
{
    data_mem.store_value(address, value);
}

uint32_t CPU::get_reg(uint32_t address)
{
    return reg_file[address];
}

void CPU::set_reg(uint32_t address, uint32_t value)
{
    reg_file[address] = value;
}

void CPU::load_instructions(std::vector<Instruction*> program)
{
    prog_mem.load_instructions(program);
}

void CPU::increment_pc(int add)
{
    program_counter = program_counter + add;
}

void CPU::show_instructions()
{
    prog_mem.show();
}

int CPU::type()
{
    return CPUId;
}

CPU_state::CPU_state() : error{false}, any_change{false} {}

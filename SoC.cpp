
#include "SoC.h"

SoC::SoC(int pins_number) : pins_number{pins_number}
{

}

void SoC::ext_wire(int pin, int reg)
{

}

void SoC::load_program(std::string path)
{
    std::ifstream hex_code(path);
    std::string current_line;
    std::vector<Instruction*> instructions;

    while (std::getline(hex_code, current_line))
    {
        if(current_line.size() > 0)
        {
            uint32_t hex_instruction = strtoul(current_line.c_str(), nullptr, 16);
            Instruction * new_instruction = get_instruction_from(hex_instruction);
            instructions.push_back(new_instruction);
        }
    }
    CPU * my_cpu = CPUs.at(0);

    my_cpu->load_instructions(instructions);
}

void SoC::add(HardwareBlock *HB)
{
    if (HB->type() == PeripheralId )
    {
        peripherals.push_back((Peripheral*)HB);
    }
    else if (HB->type() == CPUId)
    {
        std::vector<Instruction*> vector_nop;
        CPU * my_cpu = (CPU*)HB;
        CPUs.push_back(my_cpu);
        for(int i = 0; i < my_cpu->get_prog_mem_size(); ++i)
            vector_nop.push_back(new Instruction_nop);
        my_cpu->load_instructions(vector_nop);
    }
}

void SoC::int_wire(int cpu_reg, int per_reg)
{
}

bool SoC::execute(double time_lapse, int freq)
{

    if (CPUs.empty())
        return true;

    int num_cycles = (int)(time_lapse*freq);
    std::vector<CPU*>::iterator current_CPU;
    CPU_state cpu_state;

    for (int i = 0; i < num_cycles; ++i)
        for (current_CPU = CPUs.begin(); current_CPU < CPUs.end(); current_CPU++)
        {
            cpu_state = (*current_CPU)->execute_instruction();
            if (cpu_state.error)
                return true;
        }

    return false;
}

Instruction * get_instruction_from(uint32_t i)
{
    uint32_t op_code = get_opcode(i);
    switch (op_code)
    {
        case 0:
            if (i == 0)
                return new Instruction_nop();
            else
                return new Instruction_add(get_rs(i), get_rt(i), get_rd(i));

        case 43:
            return new Instruction_sw(get_rs(i), get_rt(i), get_comp_const(i));

        case 35:
            return new Instruction_lw(get_rs(i), get_rt(i), get_comp_const(i));

        case 15:
            return new Instruction_lui(get_rt(i), get_comp_const(i));

        case 13:
            return new Instruction_ori(get_rs(i), get_rt(i), get_comp_const(i));

        default:
            return new Instruction_nop();
    }
}

uint32_t get_opcode(uint32_t hex_instruction)
{
    return (hex_instruction & (0b111111 << (32-6))) >> (32-6);
}

uint32_t get_rs(uint32_t hex_code)
{
    return (hex_code & (0b11111 << 21)) >> 21 ;
}

uint32_t get_rt(uint32_t hex_code)
{
    return (hex_code & (0b11111 << 16)) >> 16;
}

uint32_t get_rd(uint32_t hex_code)
{
    return (hex_code & (0b11111 << 11)) >> 11;
}

uint32_t get_comp_const(uint32_t hex_code)
{
    return (hex_code & 0xffff);
}

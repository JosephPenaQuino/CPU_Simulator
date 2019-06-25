
#include "SoC.h"

SoC::SoC(int pins_number) : pins_number{pins_number}
{

}

void SoC::ext_wire(int pin, int reg)
{

}

void SoC::load_program(std::string path)
{

}

void SoC::add(HardwareBlock *HB)
{
    if (HB->type() == CPUId)
    {
        peripherals.push_back((Peripheral*)HB);
    }
    else if (HB->type() == PeripheralId)
    {
        CPUs.push_back((CPU*)HB);
    }
}

void SoC::int_wire(int cpu_reg, int per_reg)
{
}

bool SoC::execute(double time_lapse, int freq)
{
    if (CPUs.empty())
        return false;

    int num_cycles = (int)(time_lapse*freq);
    std::vector<CPU*>::iterator current_CPU;
    CPU_state cpu_state;

    for (int i = 0; i < num_cycles; ++i)
        for (current_CPU = CPUs.begin(); current_CPU < CPUs.end(); current_CPU++)
        {
            cpu_state = (*current_CPU)->execute_instruction();
            if (cpu_state.error)
                return false;
        }

    return true;
}

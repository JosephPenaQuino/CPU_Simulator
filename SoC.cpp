
#include "SoC.h"

SoC::SoC(int pins_number)
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

}

void SoC::int_wire(int cpu_reg, int per_reg)
{

}

void SoC::execute(double time_lapse, int freq)
{
    int num_cycles = (int)(time_lapse*freq);

    for (int i = 0; i < num_cycles; ++i)
    {

    }
}

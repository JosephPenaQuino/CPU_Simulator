#ifndef CPU_SIMULATOR_MIPS_CPU_H
#define CPU_SIMULATOR_MIPS_CPU_H

#include "CPU.h"
#include <string>

class MIPS_CPU : public CPU
{
private:

public:
    MIPS_CPU(int data_memory_size, int program_memory_size);
    void wire(std::string type, int address, std::string reg);
};


#endif //CPU_SIMULATOR_MIPS_CPU_H

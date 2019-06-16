#ifndef CPU_SIMULATOR_MIPS_CPU_H
#define CPU_SIMULATOR_MIPS_CPU_H

#include "CPU.h"
#include <string>

class MIPS_CPU : public CPU
{
private:

public:
    MIPS_CPU(int data_mem_size, int program_mem_size);

};


#endif //CPU_SIMULATOR_MIPS_CPU_H

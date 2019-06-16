
#ifndef CPU_SIMULATOR_CPU_H
#define CPU_SIMULATOR_CPU_H

#include <string>
#include "HardwareBlock.h"

class CPU : public HardwareBlock
{
private:
    int data_mem_size;
    int prog_mem_size;
    int * data_mem;
    int * prog_mem;

    int program_counter;

public:
    CPU(int data_memory_size, int program_memory_size);
    int data_reg(int reg);
    int get_id(std::string reg);
    int get_data_mem_size();
    int get_prog_mem_size();

};


#endif //CPU_SIMULATOR_CPU_H

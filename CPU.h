#ifndef CPU_SIMULATOR_CPU_H
#define CPU_SIMULATOR_CPU_H

#include <string>
#include "HardwareBlock.h"

class CPU : public HardwareBlock
{
private:

public:
    CPU();
    int get_id(std::string reg);
};


#endif //CPU_SIMULATOR_CPU_H

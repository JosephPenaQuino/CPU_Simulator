#ifndef CPU_SIMULATOR_PERIPHERAL_H
#define CPU_SIMULATOR_PERIPHERAL_H

#include "HardwareBlock.h"
#include <string>

class Peripheral : public HardwareBlock
{
private:


public:
    Peripheral();
    int reg(std::string reg);
};


#endif //CPU_SIMULATOR_PERIPHERAL_H

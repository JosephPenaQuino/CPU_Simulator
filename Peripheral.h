#ifndef CPU_SIMULATOR_PERIPHERAL_H
#define CPU_SIMULATOR_PERIPHERAL_H

#include "HardwareBlock.h"
#include <string>

#define PeripheralId 2

class Peripheral : public HardwareBlock
{
private:


public:
    Peripheral();
    int reg(std::string reg);
    int type();
};


#endif //CPU_SIMULATOR_PERIPHERAL_H

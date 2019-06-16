#ifndef CPU_SIMULATOR_SOC_H
#define CPU_SIMULATOR_SOC_H

#include "HardwareBlock.h"
#include <string>

class SoC
{
private:
    int pins_number;
public:
    SoC(int pins_number);
    void add(HardwareBlock HB);
    void wire(int pin, int reg);
    void load_program(std::string path);
};


#endif //CPU_SIMULATOR_SOC_H

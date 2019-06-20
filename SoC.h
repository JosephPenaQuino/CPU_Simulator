#ifndef CPU_SIMULATOR_SOC_H
#define CPU_SIMULATOR_SOC_H

#include "HardwareBlock.h"
#include "Peripheral.h"
#include "CPU.h"
#include <string>
#include <vector>
#include <iterator>

class SoC
{
private:
    int pins_number;
    std::vector <Peripheral*> peripherals;
    std::vector <CPU*> CPUs;

public:
    explicit SoC(int pins_number);
    void add(HardwareBlock * HB);
    void ext_wire(int pin, int reg);
    void int_wire(int cpu_reg, int per_reg);
    void load_program(std::string path);
    bool execute(double time_lapse, int freq);
};

#endif //CPU_SIMULATOR_SOC_H

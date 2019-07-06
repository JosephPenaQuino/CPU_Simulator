#ifndef CPU_SIMULATOR_SOC_H
#define CPU_SIMULATOR_SOC_H

#include "HardwareBlock.h"
#include "Peripheral.h"
#include "CPU.h"
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include "MIPS_Instructions.h"
#include <unistd.h>

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

inline static uint32_t get_opcode(uint32_t hex_instruction);
Instruction * get_instruction_from(uint32_t hex_instruction);
inline static uint32_t get_rs(uint32_t hex_code);
inline static uint32_t get_rt(uint32_t hex_code);
inline static uint32_t get_rd(uint32_t hex_code);
inline static uint32_t get_comp_const(uint32_t hex_code);


#endif //CPU_SIMULATOR_SOC_H

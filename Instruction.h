
#ifndef CPU_SIMULATOR_INSTRUCTION_H
#define CPU_SIMULATOR_INSTRUCTION_H


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory.h>
#include <string>
using namespace std;
class MipsInstruction;

class Instruction{
public  :
    Instruction();
    ~Instruction();
    void LoadMipsInstruction(const char* binary_file);

    MipsInstruction& FetchNextInstruction();
    void UpdatePC();

private :
    int        PC             ;
    int               MAX_SIZE       ; //Max instruction memory size
    MipsInstruction*  data           ;
    int binary_string_to_int(string &bin_str);
};

#endif
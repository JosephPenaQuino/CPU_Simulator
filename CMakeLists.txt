cmake_minimum_required(VERSION 3.13.4)
project(CPU_Simulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPU_Simulator read_write_mem.cpp  read_mem.h main.cpp main_test.cpp main.h CPU.h CPU.cpp CPU_MIPS.cpp CPU_MIPS.h GPIO.cpp GPIO.h HardwareBlock.cpp HardwareBlock.h Instruction.h Instruction.cpp )
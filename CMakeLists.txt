cmake_minimum_required(VERSION 3.13.4)
project(CPU_Simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)



add_executable(CPU_Simulator main.cpp main_test.cpp main.h Parser.cpp Parser.h Memory.cpp Memory.h read_mem.h read_mem.cpp read_write_mem.cpp read_write_mem.h SoC.cpp SoC.h Workspace.cpp Workspace.h MIPS_CPU.cpp MIPS_CPU.h GPIO.cpp GPIO.h Peripheral.cpp Peripheral.h HardwareBlock.cpp HardwareBlock.h CPU.cpp CPU.h Instruction.cpp Instruction.h MIPS_Instructions.cpp MIPS_Instructions.h)

cmake_minimum_required(VERSION 3.13.4)
project(CPU_Simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)

<<<<<<< HEAD
add_executable(CPU_Simulator read_write_mem.cpp  read_mem.h main.cpp main_test.cpp main.h CPU.h CPU.cpp CPU_MIPS.cpp CPU_MIPS.h GPIO.cpp GPIO.h HardwareBlock.cpp HardwareBlock.h Instruction.h Instruction.cpp )
=======

add_executable(CPU_Simulator main.cpp main_test.cpp main.h SoC.cpp SoC.h Workspace.cpp Workspace.h MIPS_CPU.cpp MIPS_CPU.h GPIO.cpp GPIO.h Peripheral.cpp Peripheral.h HardwareBlock.cpp HardwareBlock.h CPU.cpp CPU.h Instruction.cpp Instruction.h)
>>>>>>> 8bb98e110ab725c27cf730587efb64c6c757a536

# Central Processing Unit Simulator

Central processing unit (CPU) Simulator is the final project of Objected Oriented Programming Course at UTEC.
## Background
Our project allows a real CPU simulation. To achieve our purpose we need to define all parts of CPU and use
a System on chip (SoC) and MIPS architecture.
### CPU COMPONENTS
#### System on Chip
Is a technology of embedded systems, it improves the integration in only one chips, reduces the costs and build
a faster systems.
SoC includes a Hardware block composed by CPU, RM and RWM memories, input and output 
peripherals.
#### Hardware block

This block is subdivided in hardware blocks depending the type of SoC.
To achieve our purposes, we implement a CPU, RAM and ROM memories and Peripherals.
* Central processing unit (CPU): Is the electronic circuitry within a computer that control instructions and my_data flow.
In this project we use a Microprocessor without Interlocked Pipelined Stages (MIPS).
* Read memory (RM): It is a memory segment that only allows to read memory by  my_data bus addresses.
* Read write memory (RWM): It is a memory segment that can be read from and written too by my_data bus addresses.
* Peripheral: Is a hardware input or output device, that gives a computer additional functionality, the implement of this
it is a General purpose input/output(GPIO).
* General purpose input/output (GPIO):  Is a digital pin on a integrated circuit controllable by the user at run time,
GPIO is implemented and defined by the designer.

### MIPS
Microprocessor without Interlocked Pipelined Stages (MIPS) is a Reduced instruction set computer(RISC), it means a architecture of 
interlacing by instruction.
There are multiple versions of MIPS. In this project we use a 32 bit.

The role that MIPS architecture assumes in the project is essential to give a interlacing architecture CPU
to SoC, using a MIPS instructions set 32 bits.
 
### Assembly
It is a low programming language, it is composed by instructions directly to hardware blocks or machine architecture
It has a one statement per instruction,  the statements are directives to locate the block to change register by an instruction.
In addition of term, each assembly language is specific to particular computer architecture and operating system.

### Simulators



## Objectives

* XD
* XD
* XD

## Installation





## Usage

### Case 1: Modify Data Memory
#### C Code


#### Assembly


#### Binary Code


### Case 2 : Turn on LED

#### C Code


#### Assembly


#### Binary Code


### Case 3 : Read Pin

#### C Code


#### Assembly


#### Binary Code



## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

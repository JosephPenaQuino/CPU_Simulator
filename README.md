# Central Processing Unit Simulator

Central processing unit (CPU) Simulator is the final project of Objected Oriented Programming Course at UTEC.
![black_box_diagram](https://user-images.githubusercontent.com/49255376/60748096-0fa23700-9f50-11e9-9201-aaab1c959b25.PNG)
## Background
Our project allows a real CPU simulation in C++, using  Concurrent, Oriented Objects and Generic programming
also the Standard Library C++ to achieve our purpose we need to define all parts of CPU and use
a System on chip (SoC), all of that through MIPS architecture.
In addition, to managed the efficient simulation we implement a TDD (Test Driven Development), that allows to
"shape" CPU and do. 

 ![instructionRIJ](https://user-images.githubusercontent.com/49255376/60747787-9275c280-9f4d-11e9-9024-dfedc6062ba4.png)

 
### CPU COMPONENTS
#### System on Chip
Is a technology of embedded systems, it improves the integration in only one chips, reduces the costs and build
a faster systems.
SoC includes a Hardware block composed by CPU, RM and RWM memories, input and output 
peripherals.
#### Hardware block

This block is subdivided in hardware blocks depending the type of SoC.
To achieve our purposes, we implement a CPU, RM and RWM memories and Peripherals.
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

* Simulate a CPU in language C++, using an architecture SoC and MIPS.
* Implement a CPU simulation synthesize and apply concurrent programming, oriental object programming, generic programming, 
standard library C++. 
* Merge C++ programming tools with a CPU and do possible the simulation.
* Change data in a virtual memory to interact with peripherals (our purpose is introduce a binary code 
and get a sight of LED ON/OFF and read an input.

## Installation


## Usage
CPU simulator allows modify and read data memory through the hexadecimal input, it will be 
decode to instruction by a MIPS PARSER, once it has the instruction Register, Immediate or Jump form type.  

 
### Case 1: TURN ON LED
#### C Code

    
#### Assembly
    ; -------------------------------------------
    ;
    ;	Title:	Turn on Led
    ;
    ;	Cofigurations:
    ;		-	Led connected at pin 0
    ;		- 	DDRB 	:	0x0D
    ;		-	PORTB	:	0x0E
    ; -------------------------------------------
    
    ; Put 0x01 at MEM[0x0D]
    lui $1, 0x0000		; $1 <- 0 * (2^16)
    ori $8, $1, 0x0D	; $8 <- $1 | 0x0D
    ori $9, $1, 0x01	; $9 <- $1 | 0x01
    sw	$8, 0($9)		; MEM[$8+0] <- $9
    
    ; Clean registers 8
    lui $8, 0x0000		; %8 <- 0 * (2^16)
    
    ; Put 0x01 at MEM[0x0E]
    ori $8, $1, 0x0E	; $8 <- $1 | 0x0E
    sw	$8, 0($9)		; MEM[$8+0] <- $9

#### Binary Code
    
    3c010000
    3428000d
    34290001
    ad280000
    3c080000
    3428000e
    ad280000

### Case 2 : Modify data memory

#### C Code


#### Assembly


#### Binary Code


### Case 3 : Read Pin

#### C Code


#### Assembly
    ; -------------------------------------------
    ;
    ;	Title:	Read Pin
    ;
    ;	Cofigurations:
    ;		-	Readed Pin at pin 0
    ;		- 	DDRB 	:	0x0D
    ;		-	PORTB	:	0x0E
    ; -------------------------------------------
    
    ; This program demonstrates a Read Pin
    ; Data Segment
    lui $16, 4097  ;0x10010000 Base address
    lw $9, 0($16)  ; Using load word instruction
    lw $10, 4($16)
    lw $11, 8($16)
    lw $12, 12($16)
    lw $13, 12($16)
    ori $2, $0, 10
    lui $16, 0x00000000 ;Clean register

#### Binary Code

    3c101001
    8e090000
    8e0b0008
    8e0c000c
    8e0d000c
    3402000a
    3c100000

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## References



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

* Simulate a CPU in language C++, using an architecture SoC and MIPS.
* Implement a CPU simulation synthesize and apply concurrent programming, oriental object programming, generic programming, 
standard library C++. 
* Merge C++ programming tools with a CPU and do possible the simulation.
* Change data in a virtual memory to interact with peripherals (our purpose is introduce a binary code 
and get a sight of LED ON/OFF and read an input.

## Installation





## Usage

### Case 1: TURN ON LED
#### C Code
USING A PIC 16F84A
    
    
    #define _XTAL_FREQ 8000000

    #include <xc.h>

    // BEGIN CONFIG
    #pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
    #pragma config WDTE = ON // Watchdog Timer Enable bit (WDT enabled)
    #pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
    #pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
    #pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
    #pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
    #pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
    #pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
    //END CONFIG
    
    int main()
    {
      TRISB0 = 0; //RB0 as Output PIN
      while(1)
      {
        RB0 = 1;  // LED ON
        __delay_ms(1000); // 1 Second Delay
        RB0 = 0;  // LED OFF
      }
      return 0;
    }
    
#### Assembly

USING A PIC 16F84A


    TMR0 	EQU	1
    ZEROBIT	EQU	2
    STATUS	EQU	3
    PORTA	EQU	5
    PORTB	EQU	6
    OPTION_R EQU	81H
    TRISA	EQU	85H
    TRISB	EQU	86H
    COUNT	EQU	0CH


    LIST P=16f84a
    ORG 0
    GOTO START

    __CONFIG H'3FF0'


    DELAY5	CLRF	TMR0
    LOOPA	MOVF	TMR0,W
	SUBLW	.32
	BTFSS	STATUS,ZEROBIT
	GOTO	LOOPA
	RETLW	0


    START 	BSF	STATUS,5
	MOVLW	B'00011111'
	MOVWF	TRISA

	MOVLW	B'00000000'
	MOVWF	TRISB

	MOVLW	B'00000111'
	MOVWF	OPTION_R

	BCF	STATUS,5
	CLRF	PORTA
	CLRF	PORTB

    ----------------------------------
        TO DISPLAY FILE AND COUNT TO ZERO

	MOVLW	.5
	MOVWF	COUNT

    BEGIN	BTFSC	PORTA,0
	GOTO 	BEGIN
	GOTO	SEQ1

    SEQ1	MOVLW	B'01010101'
	MOVWF	PORTB
	CALL	DELAY5
	MOVLW	B'10101010'
	MOVWF	PORTB
	CALL	DELAY5
	MOVLW	B'00000000'
	MOVWF	PORTB
	DECFSZ	COUNT
	GOTO	SEQ1
	GOTO	BEGIN



    END


#### Binary Code
    :020000040000FA
    :10000000072881010108203C031D022800348316C3
    :100010001F30850000308600073081008312850183
    :10002000860105308C0005181328162855308600E7
    :100030000120AA3086000120003086008C0B162893
    :02004000132883
    :02400E00F03F81
    :00000001FF



### Case 2 : Modify data memory

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

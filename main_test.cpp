#include "main.h"

SCENARIO("Working on a simple MIPS processor that turns-on a LED")
{
    GIVEN("A work space with only one SoC")
    {
        const int number_pins = 8;

        Workspace my_workspace;
        SoC my_soc(number_pins);
        my_workspace.add(&my_soc);

        WHEN("The SoC owns a MIPS processor and a GPIO")
        {
            const int number_ports = 1;
            const int number_of_pins_per_port[number_ports] = {8};
            const int data_memory_size = 2000;
            const int program_memory_size = 1600;

            MIPS_CPU my_cpu(data_memory_size, program_memory_size);
            GPIO my_gpio(number_ports, number_of_pins_per_port);

            my_cpu.wire(0x55, "MCUCR");
            my_cpu.wire(0x25, "PORTB");
            my_cpu.wire(0x24, "DDRB");
            my_cpu.wire(0x23, "PINB");

            my_soc.add(my_cpu);
            my_soc.add(my_gpio);

            my_soc.wire(6, my_cpu.get_id("reset"));
            my_soc.wire(7, my_cpu.get_id("GND"));
            my_soc.wire(8, my_cpu.get_id("PWR"));

            my_soc.wire(1, my_gpio.get_id("PIN1"));
            my_soc.wire(2, my_gpio.get_id("PIN2"));
            my_soc.wire(3, my_gpio.get_id("PIN3"));
            my_soc.wire(4, my_gpio.get_id("PIN4"));
            my_soc.wire(5, my_gpio.get_id("PIN5"));


            THEN("A program is loaded in the program memory of the SoC")
            {
                const string code_path = "code.hex";
                my_soc.load_program(code_path);
                REQUIRE(my_workspace.execute_all());
            }
        }
    }
}
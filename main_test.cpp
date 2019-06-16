#include "main.h"

SCENARIO("Working on a simple MIPS processor that turns-on a LED")
{
    GIVEN("A work space with only one SoC")
    {
        const int number_pins = 8;

        Workspace my_workspace;
        SoC my_soc(number_pins);
        my_workspace.add(&my_soc);

        REQUIRE(my_workspace.get_size() == 1);
        REQUIRE(my_workspace.get_SoC(0) == &my_soc);

        WHEN("The SoC owns a MIPS processor and a GPIO")
        {
            const int number_ports = 1;
            const int number_of_pins_per_port[number_ports] = {8};
            const int data_memory_size = 2000;
            const int program_memory_size = 1600;

            MIPS_CPU my_cpu(data_memory_size, program_memory_size);
            GPIO my_gpio(number_ports, number_of_pins_per_port);

            REQUIRE(my_cpu.get_data_mem_size() == 2000);
            REQUIRE(my_cpu.get_prog_mem_size() == 1600);

            my_soc.add(&my_cpu);
            my_soc.add(&my_gpio);

            my_soc.int_wire(my_cpu.data_reg(0x55), my_gpio.reg("MCUCR"));
            my_soc.int_wire(my_cpu.data_reg(0x25), my_gpio.reg("PORTB"));
            my_soc.int_wire(my_cpu.data_reg(0x24), my_gpio.reg("DDRB"));
            my_soc.int_wire(my_cpu.data_reg(0x23), my_gpio.reg("PINB"));

            my_soc.ext_wire(6, my_cpu.get_id("reset"));
            my_soc.ext_wire(7, my_cpu.get_id("GND"));
            my_soc.ext_wire(8, my_cpu.get_id("PWR"));

            my_soc.ext_wire(1, my_gpio.pin_id(0));
            my_soc.ext_wire(2, my_gpio.pin_id(1));
            my_soc.ext_wire(3, my_gpio.pin_id(2));
            my_soc.ext_wire(4, my_gpio.pin_id(3));
            my_soc.ext_wire(5, my_gpio.pin_id(4));


            THEN("A program is loaded in the program memory of the SoC")
            {
                const std:: string code_path = "code.hex";
                my_soc.load_program(code_path);
                int time_lapse = 10;
                int frequency = 1000;
                REQUIRE(my_workspace.execute_all(time_lapse, frequency));
            }
        }
    }
}
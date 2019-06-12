#include "main.h"

SCENARIO("Working on a simple MIPS processor that turns-on a LED")
{
    GIVEN("A work space with only one SoC")
    {
        Workspace my_workspace;
        SoC my_soc;
        my_workspace.add(&my_soc);

        WHEN("The SoC owns a processor and a GPIO")
        {
            const int number_ports = 2;
            const int number_of_pins_per_port[number_ports] = {8, 8};
            const int data_memory_size = 4000;
            const int program_memory_size = 1000;

            MIPS_CPU my_cpu(data_memory_size, program_memory_size);
            GPIO my_gpio(number_ports, number_of_pins_per_port);

            my_soc.add(my_cpu);
            my_soc.add(my_gpio);

            THEN("A program is loaded in the program memory of the SoC")
            {
                const string code_path = "code.hex";
                my_soc.load_program(code_path);
                REQUIRE(my_workspace.execute_all());
            }
        }
    }
}
#include "main.h"

SCENARIO("Working on a simple MIPS processor that turns-on a LED")
{
    GIVEN("Testing Instructions")
    {
        const int data_memory_size = 16;
        const int program_memory_size = 32;
        MIPS_CPU my_cpu(data_memory_size, program_memory_size);

        std::vector<Instruction*> program;
        // TODO: Use make_unique
        program.emplace_back(new Instruction_lui(0x01, 0));             // reg[0x01] <- 0 * (2^16)
        program.emplace_back(new Instruction_ori(0x0A, 0x01, 0x102));   // reg[0x0A] <- reg[0x01] | 0x102
        program.emplace_back(new Instruction_lui(0x01, 0));             // reg[0x01] <- 0 * (2^16)
        program.emplace_back(new Instruction_ori(0x09, 0x01, 0x07));    // reg[0x09] <- reg[0x01] | 0x07
        program.emplace_back(new Instruction_sw(0x09, 0x0A, 0));        // MEM[reg[0x0A]] <- reg[0x0A] + 0
        my_cpu.load_instructions(program);

        std::cout << "---------------------------" << std::endl;
        std::cout << "Data Memory before program:" << std::endl;
        my_cpu.print_data_memory();

        my_cpu.execute_instruction();
        my_cpu.execute_instruction();
        my_cpu.execute_instruction();
        my_cpu.execute_instruction();
        my_cpu.execute_instruction();

        std::cout << "---------------------------" << std::endl;
        std::cout << "Data Memory after program:" << std::endl;
        my_cpu.print_data_memory();
    }

    GIVEN("Test Parser from hex code to instructions")
    {
        const int data_memory_size = 16;
        const int program_memory_size = 32;
        const int number_pins = 8;
        const std::string path_code = "../test.hex";
        MIPS_CPU my_cpu(data_memory_size, program_memory_size);
        SoC my_soc(number_pins);
        my_soc.add(&my_cpu);

        my_soc.load_program(path_code);

        std::cout << "---------------------------" << std::endl;
        std::cout << "Data Memory before program:" << std::endl;
        my_cpu.print_data_memory();

        my_cpu.execute_instruction();
        my_cpu.execute_instruction();
        my_cpu.execute_instruction();
        my_cpu.execute_instruction();
        my_cpu.execute_instruction();


        std::cout << "---------------------------" << std::endl;
        std::cout << "Data Memory after program:" << std::endl;
        my_cpu.print_data_memory();
    }

    GIVEN("Test SoC::execute(time_lapse, frequency)")
    {
        const int data_memory_size = 16;
        const int program_memory_size = 32;
        const int number_pins = 8;
        const int time_lapse = 1;
        const int freq = 100;
        const std::string path_code = "../test.hex";
        MIPS_CPU my_cpu(data_memory_size, program_memory_size);
        SoC my_soc(number_pins);
        my_soc.add(&my_cpu);

        my_soc.load_program(path_code);

        std::cout << "---------------------------" << std::endl;
        std::cout << "Data Memory before program:" << std::endl;
        my_cpu.print_data_memory();

        my_soc.execute(time_lapse, freq);


        std::cout << "---------------------------" << std::endl;
        std::cout << "Data Memory after program:" << std::endl;
        my_cpu.print_data_memory();
    }


    GIVEN("A work space with only one SoC")
    {
        const int number_pins = 8;

        Workspace my_workspace;
        SoC my_soc(number_pins);
        my_workspace.add(&my_soc);

        WHEN("The SoC owns a MIPS processor and a GPIO")
        {
            const int number_ports = 1;
            const int number_of_pins_per_port[number_ports] = {5};
            const int data_memory_size = 2000;
            const int program_memory_size = 1600;

            MIPS_CPU my_cpu(data_memory_size, program_memory_size);
            GPIO my_gpio(number_ports, number_of_pins_per_port);

            my_soc.add(&my_cpu);
            my_soc.add(&my_gpio);

            my_soc.int_wire(my_cpu.data_reg(0x55), my_gpio.reg("MCUCR"));
            my_soc.int_wire(my_cpu.data_reg(0x0E), my_gpio.reg("PORTB"));
            my_soc.int_wire(my_cpu.data_reg(0x0D), my_gpio.reg("DDRB"));
            my_soc.int_wire(my_cpu.data_reg(0x0F), my_gpio.reg("PINB"));

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
                REQUIRE(my_workspace.get_size() == 1);
                REQUIRE(my_workspace.get_SoC(0) == &my_soc);
                REQUIRE(my_cpu.get_data_mem_size() == 2000);
                REQUIRE(my_cpu.get_prog_mem_size() == 1600);
                REQUIRE(my_workspace.execute_all(time_lapse, frequency));
            }
        }
    }
}
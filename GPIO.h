#ifndef CPU_SIMULATOR_GPIO_H
#define CPU_SIMULATOR_GPIO_H

#include "Peripheral.h"
#include <string>

class GPIO : public Peripheral
{
private:

public:
    GPIO(const int number_ports, const int number_pins_per_port[]);
    int get_id(std::string reg);
};


#endif //CPU_SIMULATOR_GPIO_H

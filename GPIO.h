
#ifndef CPU_SIMULATOR_GPIO_H
#define CPU_SIMULATOR_GPIO_H

#include "Peripheral.h"
#include <string>

class GPIO : public Peripheral
{
private:
    const int number_pins;

public:
    GPIO(const int number_pins);
    int pin_id(int reg);
};

#endif
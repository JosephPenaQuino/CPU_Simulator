#ifndef CPU_SIMULATOR_READ_MEM_H
#define CPU_SIMULATOR_READ_MEM_H

#include "Memory.h"
#include <iostream>
#include <vector>

template< typename T>
class read_mem : public Memory<T> {
private:
    using Memory<T>::size;
public:
    explicit read_mem(int size);
    void load_instructions(std::vector<T> &);
    T get_instructions(int address);
};

template<typename T>
read_mem<T>::read_mem(int size) : Memory<T>(size) {}

template<typename T>
T read_mem<T>::get_instructions(int address)
{
    if (address < size && address >= 0)
        return Memory<T>::load(address);
    else
        return T();
}

template<typename T>
void read_mem<T>::load_instructions(std::vector<T> &instructions)
{
    if (instructions.size() <= size)
    {
        int address = 0;
        for(auto const& current_instruction: instructions)
        {
            Memory<T>::store(address, current_instruction);
            address++;
        }
    }
}


#endif //CPU_SIMULATOR_READ_MEM_H

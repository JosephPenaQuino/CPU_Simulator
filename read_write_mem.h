#ifndef CPU_SIMULATOR_READ_WRITE_MEM_H
#define CPU_SIMULATOR_READ_WRITE_MEM_H
#include <vector>
#include <iostream>
#include "Memory.h"
//Template de bytes = {8, 16, 32, 64}
template< typename  T>
class read_write_mem : public Memory<T> {

public:
    read_write_mem(int size);
    read_write_mem(std::vector<T>, int size);
    void load_value(int address);
    void write_value(int address, T value);
};
template<typename T>
read_write_mem<T>::read_write_mem(int size) : Memory(size) size {size}{}

template<typename T>
read_write_mem<T>::read_write_mem(vector<T> data, int size)
{
    this -> size = size;
    data.resize(size);
}

template<typename T>
void read_write_mem<T>::load_value(int address)
{
    data.at(address);
}
template<typename T>
void read_write_mem<T>::write_value(int address, T value)
{
    for (auto i = data.begin(); i != data.end(); i++)
    {
        data.emplace_back(address);
    }
    copy(begin(data), end(data), begin(data));
}


#endif //CPU_SIMULATOR_READ_WRITE_MEM_H

#ifndef CPU_SIMULATOR_READ_WRITE_MEM_H
#define CPU_SIMULATOR_READ_WRITE_MEM_H
#include "Memory.h"

template< typename  T>
class read_write_mem : public Memory<T> {

public:
    explicit read_write_mem(int size);
    T load_value(int address);
    void store_value(int address, T value);
};

template<typename T>
read_write_mem<T>::read_write_mem(int size) : Memory<T>(size) {}

template<typename T>
T read_write_mem<T>::load_value(int address)
{
    return Memory<T>::load(address);
}
template<typename T>
void read_write_mem<T>::store_value(int address, T value)
{
    Memory<T>::store(address, value);
}




#endif //CPU_SIMULATOR_READ_WRITE_MEM_H

#ifndef CPU_SIMULATOR_MEMORY_H
#define CPU_SIMULATOR_MEMORY_H

#include <vector>
template<typename T>
class Memory {
private:
    T * my_data;
    int size;

protected:
    void store(int address, T value);
    T load(int address);

public:
    explicit Memory(int size);

};

template<typename T>
Memory<T>::Memory(int size) : size{size}
{
    my_data = new T[size];
}

template<typename T>
void Memory<T>::store(int address, T value)
{
    my_data[address] = value;
}

template<typename T>
T Memory<T>::load(int address)
{
    return my_data[address];
}




#endif //CPU_SIMULATOR_MEMORY_H

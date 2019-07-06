#ifndef CPU_SIMULATOR_MEMORY_H
#define CPU_SIMULATOR_MEMORY_H

#include <vector>
#include <iostream>

template<typename T>
class Memory {
private:
    T * my_data;


protected:
    int size;
    void store(int address, T value);
    T load(int address);

public:
    explicit Memory(int size);
    void show();

};

template<typename T>
Memory<T>::Memory(int size) : size{size}
{
    my_data = new T[size] {};
}

template<typename T>
void Memory<T>::store(int address, T value)
{
    my_data[address] = value;
}

template<typename T>
T Memory<T>::load(int address)
{
    if (address < size && address >= 0)
        return my_data[0];
    else
        return T();
}

template<typename T>
void Memory<T>::show()
{
    for(int i = 0; i < 5; ++i)
    {
        std::cout << my_data[i]->get_id() << std::endl;
    }
}


#endif //CPU_SIMULATOR_MEMORY_H

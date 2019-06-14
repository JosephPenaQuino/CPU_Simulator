//
// Created by albin on 13/06/2019.
//

#ifndef CPU_SIMULATOR_READ_WRITE_MEM_H
#define CPU_SIMULATOR_READ_WRITE_MEM_H

#include <vector>
#include <iostream>
using namespace std;
//Template de bytes = {8, 16, 32, 64}
template< typename  T>
class read_write_mem {
private:
    vector<T> data;
    int size;
public:
    read_write_mem(vector<T>, int size);
    void read_value(int address);
    void write_value(int address, T value);
};

template<typename T>
read_write_mem<T>::read_write_mem(vector<T> data, int size) {
this -> size = size;
data.resize(size);
}

template<typename T>
void read_write_mem<T>::read_value(int address)
{



}

template<typename T>
void read_write_mem<T>::write_value(int address, T value)
{
    for (auto i = data.begin(); i != data.end(); i++)
    {
        data.emplace_back(address);
    }

}
#endif //CPU_SIMULATOR_READ_WRITE_MEM_H

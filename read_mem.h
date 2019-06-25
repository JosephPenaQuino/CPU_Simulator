#ifndef CPU_SIMULATOR_READ_MEM_H
#define CPU_SIMULATOR_READ_MEM_H

#include <vector>
#include <iostream>
using namespace std;
template< typename T>
class read_mem {
private:
    int size;
    vector<T> instructions_list;
public:
    read_mem(int size)
    {

    }

    T get_instructions(int address) {
        return T();
    }
};


#endif //CPU_SIMULATOR_READ_MEM_H

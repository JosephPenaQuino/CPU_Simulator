#ifndef CPU_SIMULATOR_MEMORY_H
#define CPU_SIMULATOR_MEMORY_H

#include <vector>
template<typename T>
class Memory {
private:
    std::vector<T> data;
    int size;
public:
Memory(int size) : size{size}{};
};


#endif //CPU_SIMULATOR_MEMORY_H

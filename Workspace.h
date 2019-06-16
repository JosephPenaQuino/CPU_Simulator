#ifndef CPU_SIMULATOR_WORKSPACE_H
#define CPU_SIMULATOR_WORKSPACE_H

#include <list>

class SoC;

class Workspace
{
private:
    std::list <SoC*> SoC_list;

public:
    Workspace();
    void add(SoC * new_soc);
    bool execute_all(double time_lapse, int frequency);
    int get_size();
    SoC * get_SoC(int key);
};

#endif //CPU_SIMULATOR_WORKSPACE_H

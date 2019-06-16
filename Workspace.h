#ifndef CPU_SIMULATOR_WORKSPACE_H
#define CPU_SIMULATOR_WORKSPACE_H

class SoC;

class Workspace
{
private:

public:
    Workspace();
    void add(SoC * new_soc);
    bool execute_all();
};


#endif //CPU_SIMULATOR_WORKSPACE_H

#include "Workspace.h"

Workspace::Workspace() = default;

void Workspace::add(SoC *new_soc)
{
    SoC_list.push_back(new_soc);
}

int Workspace::get_size()
{
    return SoC_list.size();
}

SoC *Workspace::get_SoC(int key)
{
    std::list<SoC*>::iterator ptr = SoC_list.begin();
    advance(ptr, key);

    return *ptr;
}

bool Workspace::execute_all(double time_lapse, int frequency)
{
    std::list<SoC*>::iterator ptr;

    for (ptr = SoC_list.begin(); ptr != SoC_list.end(); ++ptr)
        (*ptr)->execute(time_lapse, frequency);

    return true;
}
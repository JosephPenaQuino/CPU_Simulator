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
    auto ptr = SoC_list.begin();
    advance(ptr, key);

    return *ptr;
}

bool Workspace::execute_all(double time_lapse, int frequency)
{
    std::list<SoC*>::iterator current_SoC;
    bool is_any_error = false;
    for (current_SoC = SoC_list.begin(); current_SoC != SoC_list.end(); ++current_SoC)
    {
        is_any_error = (*current_SoC)->execute(time_lapse, frequency);
        if (is_any_error)
            return false;
    }
    return true;
}
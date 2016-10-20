#include "../header/and.h"

And::And(std::vector<std::string> vs)
{
    v = vs;
}

std::vector<std::string> And::get()
{
    return v;
}
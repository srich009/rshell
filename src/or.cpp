#include "../header/or.h"

Or::Or(std::vector<std::string> vs)
{
    v = vs;
}

std::vector<std::string> get()
{
    return v;
}
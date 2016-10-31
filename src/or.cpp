#include "../header/or.h"

Or::Or(std::string vs)
{
    v = vs;
}

std::string Or::get()
{
    return v;
}

std::string Or::type()
{
    return "Or";
}

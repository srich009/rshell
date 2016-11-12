#include "../header/or.h"

Or::Or(std::string instr)
{
    str = instr;
}

Or::~Or() // ?? add destructor ??
{
    ;
}

std::string Or::get()
{
    return str;
}

std::string Or::type()
{
    return "Or";
}

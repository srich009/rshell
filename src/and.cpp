#include "../header/and.h"

And::And(std::string instr)
{
    str = instr;
}

And::~And() // ?? add destructor ??
{
    ;
}

std::string And::get()
{
    return str;
}

std::string And::type()
{
    return "And";
}
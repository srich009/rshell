#include "../header/leaf_cmd.h"

Leaf::Leaf(std::string instr)
{
    str = instr;
}

Leaf::~Leaf() // ?? add destruct Leaf ??
{
    ;
}

std::string Leaf::get()
{
    return str;
}

std::string Leaf::type()
{
    return "Leaf";
}
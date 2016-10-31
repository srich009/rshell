#include "../header/and.h"

And::And(std::string vs)
{
    v = vs;
}

std::string And::get()
{
    return v;
}

std::string And::type()
{
    return "And";
}
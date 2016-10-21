#include "../header/and.h"

And::And(std::string vs)
{
    v = vs;
}

std::string And::get()
{
    return v;
}
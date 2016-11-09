#include "../header/and.h"

And::And(std::string vs)
{
    v = vs;
}

And::~And() // ?? add destructor ??
{
    ;
}

std::string And::get()
{
    return v;
}

std::string And::type()
{
    return "And";
}
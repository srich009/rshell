#include "../header/semiColon.h"

Semicolon::Semicolon(std::string vs)
{
    v = vs;
}

std::string Semicolon::get()
{
    return v;
}
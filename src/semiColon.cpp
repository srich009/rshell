#include "../header/semiColon.h"

Semicolon::Semicolon(std::string vs)
{
    v = vs;
}

Semicolon::~Semicolon() // ?? add destructor ??
{
    ;
}

std::string Semicolon::get()
{
    return v;
}

std::string Semicolon::type()
{
    return "Object";
}
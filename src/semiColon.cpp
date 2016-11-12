#include "../header/semiColon.h"

Semicolon::Semicolon(std::string instr)
{
    str = instr;
}

Semicolon::~Semicolon() // ?? add destructor ??
{
    ;
}

std::string Semicolon::get()
{
    return str;
}

std::string Semicolon::type()
{
    return "Object";
}
#include "../header/semiColon"

Semicolon::Semicolon(std::vector<std::string> vs)
{
    v = vs;
}

std::vector<std::string> Semicolon::get()
{
    return v;
}
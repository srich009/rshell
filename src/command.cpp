#include "../header/command.h"

Command::Command(std::vector<std::string> vs)
{
    v = vs;
}

std::vector<std::string> Command::get()
{
    return v;
}
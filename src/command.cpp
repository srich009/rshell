#include "../header/command.h"

Command::Command(std::string vs)
{
    v = vs;
}

std::string Command::get()
{
    return v;
}
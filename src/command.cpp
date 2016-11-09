#include "../header/command.h"

Command::Command(std::string vs)
{
    v = vs;
}

Command::~Command() // ?? add destructor ??
{
    ;
}

std::string Command::get()
{
    return v;
}

std::string Command::type()
{
    return "Command";
}
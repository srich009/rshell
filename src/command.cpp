#include "../header/command.h"

Command::Command()
{}

Command::Command(std::string instr)
{
    str = instr;
}

Command::~Command() // ?? add destructor ??
{
}

std::string Command::get()
{
    return str;
}
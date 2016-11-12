#include "../header/connector.h"

Connector::Connector()
{}

Connector::~Connector()
{}

Connector::Connector(std::string instr)
{
    str = instr;
}

std::string Connector::get()
{
    return str;
}
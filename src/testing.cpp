#include "../header/testing.h"


Test::Test(std::string instr)
{
    str = instr;
}

Test::~Test() // ?? add destructor ??
{
}

std::string Test::get()
{
    return str;
}

std::string Test::type()
{
    return "Test";
}
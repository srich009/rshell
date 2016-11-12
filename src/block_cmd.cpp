#include "../header/block_cmd.h"

Block::Block(std::string instr)
{
    str = instr;
}

Block::~Block() // ?? add destruct Block ??
{
    ;
}

std::string Block::get()
{
    return str;
}

std::string Block::type()
{
    return "Block";
}
#include "../header/object.h"

Object::Object()
{}

Object::~Object()
{}

Object::Object(std::string instr)
{
    str = instr;
}

std::string Object::get()
{
    return str;
}
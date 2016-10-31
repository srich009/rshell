#include "../header/object.h"

Object::Object()
{}

Object::~Object()
{}

Object::Object(std::string vs)
{
    v = vs;
}

std::string Object::type()
{
    return "Object";
}
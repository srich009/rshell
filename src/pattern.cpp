#include "../header/pattern.h"

Pattern::Pattern(std::string str)
{
    l = new Line(str);
    i = new Interpreter();
    a = new Action();
}
//-------------------------------------

Pattern::~Pattern()
{
    delete l; // Line
    l = 0;
    delete i; // Interpreter
    i = 0;
    delete a; // Action
    a = 0;
}
//-------------------------------------

Line* Pattern::getL()
{
    return l;
}
//-------------------------------------

Interpreter* Pattern::getI()
{
    return i;
}
//-------------------------------------

Action* Pattern::getA()
{
    return a;
}
//-------------------------------------
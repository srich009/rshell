#include "../header/pattern.h"

Pattern::Pattern(std::string str)
{
    l = new Line(str);
    i = new Interpreter();
    m = new Maketree();
    a = new Action();
}
//-------------------------------------

Pattern::~Pattern()
{
    delete l;
    l = 0;
    delete i;
    i = 0;
    delete m;
    m = 0;
    delete a;
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

Maketree* Pattern::getM()
{
    return m;
}
//-------------------------------------

Action* Pattern::getA()
{
    return a;
}
//-------------------------------------
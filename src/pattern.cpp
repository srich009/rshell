#include "../header/pattern.h"

Pattern(std::string str)
{
    l = new Line();
    i = new Interpreter();
    m = new Maketree();
    a = new Action()
}
//-------------------------------------

~Pattern()
{
    // later
}
//-------------------------------------

Line* getL()
{
    return l;
}
//-------------------------------------

Interpreter* getI()
{
    return i;
}
//-------------------------------------

Maketree* getM()
{
    return m;
}
//-------------------------------------

Action* getA()
{
    return a;
}
//-------------------------------------
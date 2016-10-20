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
#include "../header/line.h"

Line::Line(std::string str)
{
    input = str;
}
//-------------------------------------

Line::~Line()
{
    //delete objects
    for(unsigned i = 0; i < v.size(); i++)
    {
        delete v.at(i);
        v.at(i) = 0;
    }
}
//-------------------------------------

std::string Line::getString()
{
    return input;
}
//-------------------------------------

std::vector<Object*>& Line::getVec()
{
    return v;
}
//-------------------------------------


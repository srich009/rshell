#include "line.h"

Line::Line(std::string str)
{
    input = str;
    root = 0;
}
//-------------------------------------

Line::~Line()
{
    // come back for
}
//-------------------------------------

std::string Line::getString()
{
    return input;
}
//-------------------------------------

std::vector<Object*> Line::getVec()
{
    return v;
}
//-------------------------------------

Node* Line::getNode()
{
    return root;
}
//-------------------------------------

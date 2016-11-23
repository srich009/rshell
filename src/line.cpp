#include "../header/line.h"

Line::Line(std::string str)
{
    input = str;
    root = 0;
}
//-------------------------------------

Line::~Line()
{
    //delete root && node destructor is recursive
    delete root;
    root = 0;
}
//-------------------------------------

std::string Line::getString()
{
    return input;
}
//-------------------------------------

Node* Line::getRoot()
{
    return root;
}
//-------------------------------------

void Line::setRoot(Node* n)
{
    this->root = n;
}
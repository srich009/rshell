// Node class implementation

#include "../header/node.h"


Node::Node(std::string s)
    : key(s), parent(0), left(0), right(0)
{}
//-----------------------------------------------   

Node::~Node() 
{
    Node* current = this;
    Node* parent = 0;
    while (current != 0)
    {
        parent = current->getPar();
        if (current->getLeft() == 0)
        {
            current = current->getLeft();
        }
        else if (current->getRight() == 0)
        {
            current = current->getRight();
        }
        else
        {
            if (parent->getRight() == current)
            {
                parent->setRight(0); // ??
            }
            else
            {
                parent->setLeft(0);
            }
            current = 0; // this line (among others) is very suspicious
        }
        current = parent;
    }
}
//------------------------------------------------

void Node::setPar(Node* n)
{
    this->parent = n;
}
//-----------------------------------------------

void Node::setLeft(Node* n)
{
    this->left = n;
}
//-----------------------------------------------

void Node::setRight(Node* n)
{
    this->right = n;
}
//-----------------------------------------------

Node* Node::getPar()
{
    return parent;
}
//-----------------------------------------------

Node* Node::getLeft()
{
    return left;
}
//-----------------------------------------------

Node* Node::getRight()
{
    return right;
}
//-----------------------------------------------

std::string Node::getKey()
{
    return key;
}
//-----------------------------------------------
// Node class implementation

#include "../header/node.h"


Node::Node(std::string s)
    : key(s), parent(0), left(0), right(0)
{}
//-----------------------------------------------   

Node::~Node() // called on root
{
    Node::clear(this);
}
//------------------------------------------------

void Node::clear(Node* n)
{
    if(n != 0)
    {
        clear(this->left);
        clear(this->right);
        delete this;
        this->parent = 0;
        this->left = 0;
        this->right = 0;
    }
}
//-----------------------------------------------

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
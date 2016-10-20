// Node class implementation

#include "node.h"


Node::Node(std::string s)
    : key(s), parent(0), left(0), right(0)
{}
//-----------------------------------------------   

Node::~Node() // called on root
{
    //clear(this->left);
    //clear(this->right);
}
//------------------------------------------------

void Node::clear(Node* n)
{
    
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


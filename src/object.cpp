#include "../header/object.h"


//==============================================================================
Object::Object()
{}

Object::~Object()
{}

Object::Object(std::string instr)
{
    str = instr;
}

std::string Object::get()
{
    return str;
}
//==============================================================================


//==============================================================================
Connector::Connector()
{}

Connector::~Connector()
{}

Connector::Connector(std::string instr)
{
    str = instr;
}

std::string Connector::get()
{
    return str;
}
//==============================================================================


//==============================================================================
And::And(std::string instr)
{
    str = instr;
}

And::~And() // ?? add destructor ??
{
    ;
}

std::string And::get()
{
    return str;
}

std::string And::type()
{
    return "And";
}
//==============================================================================


//==============================================================================
Or::Or(std::string instr)
{
    str = instr;
}

Or::~Or() // ?? add destructor ??
{
    ;
}

std::string Or::get()
{
    return str;
}

std::string Or::type()
{
    return "Or";
}
//==============================================================================


//==============================================================================
Semicolon::Semicolon(std::string instr)
{
    str = instr;
}

Semicolon::~Semicolon() // ?? add destructor ??
{
    ;
}

std::string Semicolon::get()
{
    return str;
}

std::string Semicolon::type()
{
    return "Object";
}
//==============================================================================


//==============================================================================
Command::Command()
{}

Command::Command(std::string instr)
{
    str = instr;
}

Command::~Command() // ?? add destructor ??
{
}

std::string Command::get()
{
    return str;
}
//==============================================================================


//==============================================================================
Leaf::Leaf(std::string instr)
{
    str = instr;
}

Leaf::~Leaf() // ?? add destruct Leaf ??
{
    ;
}

std::string Leaf::get()
{
    return str;
}

std::string Leaf::type()
{
    return "Leaf";
}
//==============================================================================


//==============================================================================
Block::Block(std::string instr)
{
    str = instr;
}

Block::~Block() // ?? add destruct Block ??
{
    ;
}

std::string Block::get()
{
    return str;
}

std::string Block::type()
{
    return "Block";
}
//==============================================================================
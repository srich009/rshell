#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <vector>
#include <string>


class Object
{
    protected:
    
        std::string str;
    
    public:
    
        virtual ~Object(); // Virtual destructor because abstract...
        
        Object();
    
        Object(std::string);
        
        virtual std::string get() = 0;
        
        virtual std::string type() = 0;
};
//==============================================================================


class Connector : public Object
{   
    public:
    
        virtual ~Connector(); // abstract class needs virtual destructor
    
        Connector();
        
        Connector(std::string);
        
        virtual std::string get() = 0;
        
        virtual std::string type() = 0;      
};
//==============================================================================


class And : public Connector
{
    public:
    
        And(std::string vs);
        
        ~And(); // ?? add destructor ??
        
        std::string get();
        
        std::string type();
};
//==============================================================================


class Or : public Connector
{
    public:
    
        Or(std::string);
        
        ~Or(); // ?? add destructor ??
    
        std::string get();
        
        std::string type();
};
//==============================================================================


class Semicolon : public Connector
{
    public:
    
        Semicolon(std::string);
        
        ~Semicolon(); // ?? add destructor ??
    
        std::string get();
        
        std::string type();   
};
//==============================================================================


class Command : public Object // now an Abstract base
{ 
    public:
        
        Command();
        
        Command(std::string);
        
        virtual ~Command(); // ?? add destructor ??
        
        virtual std::string get() = 0;
        
        virtual std::string type() = 0;
};
//==============================================================================


class Leaf : public Command // cmds && args
{
    public:
        
        Leaf(std::string);
        
        ~Leaf(); // ?? add destructor ??
        
        std::string get();
        
        std::string type();    
};
//==============================================================================


class Block : public Command // structure to call recurse parse on
{
    public:
        
        Block(std::string);
        
        ~Block(); // ?? add destructor ??
        
        std::string get();
        
        std::string type();
};
//==============================================================================


#endif // __OBJECT_H__
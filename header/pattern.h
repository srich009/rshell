#ifndef PATTERN_H
#define PATTERN_H

#include "line.h"
#include "interpreter.h"
#include "action.h"

class Pattern 
{
    
    private:
    
        Line* l;
    
        Interpreter* i;
    
        Action* a;
    
    public:
    
        Pattern(std::string);
        
        ~Pattern();
    
        Line* getL();
    
        Interpreter* getI();
    
        Action* getA();
    
};

#endif

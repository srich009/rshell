#ifndef PATTERN_H
#define PATTERN_H

#include "line.h"
#include "interpreter.h"
#include "maketree.h"
#include "action.h"

class Pattern 
{
    
    private:
    
        Line* l;
    
        Interpreter* i;
    
        Maketree* m;
    
        Action* a;
    
    public:
    
        Pattern(std::string);
        
        ~Pattern();
    
        Line* getL();
    
        Interpreter* getI();
    
        Maketree* getM();
    
        Action* getA();
    
};

#endif

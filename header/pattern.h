#ifndef __PATTERN_H__
#define __PATTERN_H__

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

#endif // __PATTERN_H__

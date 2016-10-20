#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <vector>
#include <string>
#include "object.h"

class Interpreter
{
    
    public:
    
        std::vector<Object*> parse(std::string s);
        
};
#endif
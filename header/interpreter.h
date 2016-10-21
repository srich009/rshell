#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <vector>
#include <string>

#include "object.h"
#include "command.h"
#include "connector.h"
#include "or.h"
#include "and.h"
#include "semiColon.h"

class Interpreter
{
    
    public:
        
        std::vector<Object*> parse(std::string s);
        
};

#endif
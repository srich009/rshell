#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>

#include "object.h"

class Command : public Object
{
    
    public:
        
        Command(std::string vs);
        
        std::string get();
        
        std::string type();
        
};

#endif
#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>

#include "object.h"

class Command : public Object // now an Abstract base
{
    
    public:
        
        Command();
        
        Command(std::string);
        
        virtual ~Command(); // ?? add destructor ??
        
        virtual std::string get() = 0;
        
        virtual std::string type() = 0;
        
};

#endif
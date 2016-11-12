#ifndef BLOCK_COMMAND_H
#define BLOCK_COMMAND_H

#include <vector>
#include <string>

#include "command.h"

class Block : public Command // structure to call recurse parse on
{
    
    public:
        
        Block(std::string);
        
        ~Block(); // ?? add destructor ??
        
        std::string get();
        
        std::string type();
        
};

#endif
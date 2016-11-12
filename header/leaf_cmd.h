#ifndef LEAF_COMMAND_H
#define LEAF_COMMAND_H

#include <vector>
#include <string>

#include "command.h"

class Leaf : public Command // cmds && args
{
    
    public:
        
        Leaf(std::string);
        
        ~Leaf(); // ?? add destructor ??
        
        std::string get();
        
        std::string type();
        
};

#endif
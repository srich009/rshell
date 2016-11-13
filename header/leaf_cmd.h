#ifndef __LEAF_COMMAND_H__
#define __LEAF_COMMAND_H__

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

#endif // __LEAF_COMMAND_H__
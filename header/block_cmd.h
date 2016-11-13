#ifndef __BLOCK_COMMAND_H__
#define __BLOCK_COMMAND_H__

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

#endif // __BLOCK_COMMAND_H__
#ifndef ACTION_H
#define ACTION_H

#include <string>

#include "node.h"

class Action
{
    public:
    
        void exec(Node*);
        
        int executr(char* cmd);
        
        // Homemade Builtin Commands
        
        // bool cd(std::string);   // change directory -> NOT USED
      
};

#endif
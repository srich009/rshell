#ifndef ACTION_H
#define ACTION_H

#include <string>

#include "object.h"

class Action
{
    public:
    
        void exec(std::vector<Object*>);
        
        int executr(char* cmd);
        
        // Homemade Builtin Commands
        
        // bool cd(std::string);   // change directory -> NOT USED
      
};

#endif
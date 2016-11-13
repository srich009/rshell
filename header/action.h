#ifndef ACTION_H
#define ACTION_H

#include <string>

#include "node.h"

class Action
{
    public:
    
        bool exec(Node*);
        
        int executr(char* cmd);

        bool eval(bool, bool, std::string);
};

#endif
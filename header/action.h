#ifndef __ACTION_H__
#define __ACTION_H__

#include <string>

#include "node.h"

class Action
{
    public:
    
        bool exec(Node*);
        
        int executr(char* cmd);
};

#endif // __ACTION_H__
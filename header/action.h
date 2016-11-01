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
        
        void exitr();           // exit
        
        // bool echo(std::string); // echo -> NOT USED
        
        // bool cd(std::string);   // change directory -> NOT USED
        
        // bool pwd(std::string);  // print working directory -> NOT USED
      
};

#endif
#ifndef ACTION_H
#define ACTION_H

#include <string>

#include "object.h"

class Action
{
    public:
    
        void exec(std::vector<Object*>);
        
        // Built in commands
        void exitr();           // exit
        
        bool echo(std::string); // echo
        
        bool cd(std::string);   // change directory
        
        bool pwd(std::string);  // print working directory
      
};

#endif
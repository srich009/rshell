#ifndef COMMAND_H
#define COMMAND_H
#include <vector>
#include <string>
#include "object.h"

class Command : public object
{
    
    protected:
    
        std::vector<std::string> v;
    
    public:
        
        Command(std::vector<std::string> vs);
        
        std::vector<std::string> get();
        
};
#endif
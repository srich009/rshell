#ifndef COMMAND_H
#define COMMAND_H
#include <vector>
#include <string>
#include "object.h"

class Command : public object
{
    
    private:
    
        std::vector<std::string> v;
    
    public:
    
        std::vector<std::string> get();
        
};
#endif
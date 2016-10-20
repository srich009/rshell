#ifndef SEMICOLON_H
#define SEMICOLON_H
#include <vector>
#include <string>
#include "connector.h"

class Semicolon : public Connector
{
    
    protected:
    
        std::vector<std::string> v;
    
    public:
    
        std::vector<std::string> get();
        
};
#endif
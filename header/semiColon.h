#ifndef SEMICOLON_H
#define SEMICOLON_H

#include <vector>
#include <string>

#include "connector.h"

class Semicolon : public Connector
{
    
    public:
    
        Semicolon(std::vector<std::string> vs);
    
        std::vector<std::string> get();
        
};
#endif
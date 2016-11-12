#ifndef SEMICOLON_H
#define SEMICOLON_H

#include <vector>
#include <string>

#include "connector.h"

class Semicolon : public Connector
{
    
    public:
    
        Semicolon(std::string);
        
        ~Semicolon(); // ?? add destructor ??
    
        std::string get();
        
        std::string type();
        
};
#endif
#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <vector>
#include <string>

#include "object.h"

class Connector : public Object
{
    
    protected:
    
        std::vector<std::string> v;
        
    public:
    
        Connector(std::vector<std::string> vs);
        
        virtual std::vector<std::string> get() = 0;
        
};
#endif
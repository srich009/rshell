#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <vector>
#include <string>

#include "object.h"

class Connector : public Object
{
        
    public:
    
        //virtual ~Connector();
    
        Connector();
        
        Connector(std::string vs);
        
        virtual std::string get() = 0;
        
};
#endif
#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include <vector>
#include <string>

#include "object.h"

class Connector : public Object
{   
    public:
    
        virtual ~Connector(); // abstract class needs virtual destructor
    
        Connector();
        
        Connector(std::string);
        
        virtual std::string get() = 0;
        
        virtual std::string type() = 0;      
};

#endif // __CONNECTOR_H__
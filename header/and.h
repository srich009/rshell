#ifndef __AND_H__
#define __AND_H__

#include <vector>
#include <string>

#include "connector.h"

class And : public Connector
{
    public:
    
        And(std::string vs);
        
        ~And(); // ?? add destructor ??
        
        std::string get();
        
        std::string type();
};

#endif // __AND_H__
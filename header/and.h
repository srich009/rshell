#ifndef AND_H
#define AND_H

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

#endif

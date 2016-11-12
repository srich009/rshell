#ifndef OR_H
#define OR_H

#include <vector>
#include <string>

#include "connector.h"

class Or : public Connector
{
    public:
    
        Or(std::string);
        
        ~Or(); // ?? add destructor ??
    
        std::string get();
        
        std::string type();
};

#endif

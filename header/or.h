#ifndef OR_H
#define OR_H

#include <vector>
#include <string>

#include "connector.h"

class Or : public Connector
{
    public:
    
        Or(std::string vs);
    
        std::string get();
};

#endif

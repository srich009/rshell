#ifndef OR_H
#define OR_H
#include <vector>
#include <string>
#include "connector.h"

class Or : public Connector
{
    protected:
    
        std::vector<std::string> v;
    
    public:
    
        Or(std::vector<std::string> vs);
    
        std::vector<std::string> get();
};
#endif
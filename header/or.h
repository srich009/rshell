#ifndef OR_H
#define OR_H
#include <vector>
#include <string>
#include "connector.h"

class Or : public Connector
{
    private:
    
        std::vector<std::string> v;
    
    public:
    
        std::vector<std::string> get();
};
#endif
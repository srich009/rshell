#ifndef __OR_H__
#define __OR_H__

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

#endif // __OR_H__

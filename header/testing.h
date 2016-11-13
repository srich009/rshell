#ifndef TEST_H
#define TEST_H

#include <vector>
#include <string>

#include "object.h"

class Test : public Object // now an Abstract base
{
    
    public:
                
        Test(std::string);
        
        ~Test(); // ?? add destructor ??
        
        std::string get();
        
        std::string type();
        
};

#endif
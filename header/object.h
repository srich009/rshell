#ifndef OBJECT_H
#define OBJECT_H
#include <vector>
#include <string>

class Object
{
    
    protected:
    
        std::vector<std::string> v;
    
    public:
    
        virtual std::vector<std::string> get() = 0;
        
};
#endif
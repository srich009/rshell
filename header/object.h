#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <string>

class Object
{
    
    protected:
    
        std::vector<std::string> v;
    
    public:
    
        virtual ~Object(); // Virtual destructor because abstract...
    
        Object(std::vector<std::string> vs);
        
        virtual std::vector<std::string> get() = 0;
        
};

#endif
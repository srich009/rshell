#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <string>

class Object
{
    
    protected:
    
        std::string v;
    
    public:
    
        virtual ~Object(); // Virtual destructor because abstract...
        
        Object();
    
        Object(std::string vs);
        
        virtual std::string get() = 0;
        
};

#endif
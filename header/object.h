#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <string>

class Object
{
    
    protected:
    
        std::string str;
    
    public:
    
        virtual ~Object(); // Virtual destructor because abstract...
        
        Object();
    
        Object(std::string);
        
        virtual std::string get() = 0;
        
        virtual std::string type() = 0;
};

#endif
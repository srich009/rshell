#ifndef __OBJECT_H__
#define __OBJECT_H__

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

#endif // __OBJECT_H__
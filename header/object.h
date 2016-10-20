#ifndef OBJECT_H
#define OBJECT_H
#include <vector>
#include <string>

class Object
{
    protected:
    
        vector<string> v;
    
    public:
    
        virtual vector<string> get() = 0;
};
#endif
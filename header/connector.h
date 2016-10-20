#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <vector>
#include <string>

class Connector : public Object
{
    protected:
        vector<string> v;
        
    public:
        virtual vector<string> get() = 0;
};
#endif
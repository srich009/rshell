#ifndef AND_H
#define AND_H
#include <vector>
#include <string>

class And : public Connector
{
    private:
    
        vector<string> v;
    
    public:
    
        vector<string> get();
};
#endif
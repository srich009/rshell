#ifndef INTERPRETER_H
#define INTERPRETER_H
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
#ifndef SEMICOLON_H
#define SEMICOLON_H
#include <vector>
#include <string>

class Semicolon : public Connector
{
    private:
    
        vector<string> v;
    
    public:
    
        vector<string> get();
};
#endif
#ifndef COMMAND_H
#define COMMAND_H
#include <vector>
#include <string>

class Command : public object
{
    private:
    
        vector<string> v;
    
    public:
    
        vector<string> get();
};
#endif
#ifndef OR_H
#define OR_H
#include <vector>
#include <string>

class Or : public Connector
{
    private:
    
        vector<string> v;
    
    public:
    
        vector<string> get();
};
#endif
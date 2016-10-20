#ifndef SEMICOLON_H
#define SEMICOLON_H
#define <vector>
#define <string>

class Semicolon : public Connector
{
    private:
        vector<string> v;
    
    public:
        vector<string> get();
};
#endif
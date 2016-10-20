#ifndef INTERPRETER_H
#define INTERPRETER_H
#define <vector>
#define <string>

class And : public Connector
{
    private:
        vector<string> v;
    
    public:
        vector<string> get();
};
#endif
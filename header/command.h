#ifndef COMMAND_H
#define COMMAND_H
#define <vector>
#define <string>

class Command : public object
{
    private:
        vector<string> v;
    
    public:
        vector<string> get();
};
#endif
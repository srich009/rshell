#ifndef OR_H
#define OR_H
#define <vector>
#define <string>

class Or : public Connector
{
    private:
        vector<string> v;
    
    public:
        vector<string> get();
};
#endif
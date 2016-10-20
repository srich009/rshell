#ifndef OR_H
#define OR_H
#include <vector>
#include <string>
#include "connector.h"

class Or : public Connector
{
<<<<<<< HEAD

=======
    protected:
    
        std::vector<std::string> v;
    
>>>>>>> 62098a3c7ab8a116ab0b3e5969fcdfea1522fe94
    public:
    
        Or(std::vector<std::string> vs);
    
        std::vector<std::string> get();
};
#endif
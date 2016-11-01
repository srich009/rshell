#ifndef __LINE_H__
#define __LINE_H__

#include <string>
#include <vector>

#include "object.h"

class Line
{

    private:
    
        // unformatted user input
        std::string input;
        
        // tokenized vector 
        std::vector<Object*> v;

    public:

        // Constructor receives string from pattern's constructor
    	Line(std::string);
    	
    	~Line();
    	
    	std::string getString();
    	
    	std::vector<Object*>& getVec();

};

#endif // __LINE_H__

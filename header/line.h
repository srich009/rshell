#ifndef __LINE_H__
#define __LINE_H__

#include <string>
#include <vector>

#include "node.h"
#include "object.h"

class Line
{

    private:
    
    // unformatted user input
    std::string input;
    
    // tokenized vector 
    std::vector<Object*> v;
    
    // Syntax Tree
    Node* root;

    public:

    // Constructor receives string from pattern's constructor
	Line(std::string);
	
	~Line();
	
	std::string getString();
	
	std::vector<Object*> getVec();
	
	Node* getNode();

};

#endif // __LINE_H__

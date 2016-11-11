#ifndef __LINE_H__
#define __LINE_H__

#include <string>
#include <vector>

#include "node.h"

class Line
{

    private:
    
        // unformatted user input
        std::string input;
        
        // root node of the abstract syntax tree
        Node* root;

    public:

        // Constructor receives string from pattern's constructor
    	Line(std::string);
    	
    	~Line();
    	
    	std::string getString();
    	
    	Node* getRoot();
    	
    	void setRoot(Node*);

};

#endif // __LINE_H__

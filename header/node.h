#ifndef __NODE_H__
#define __NODE_H__

#include <string>

class Node
{

    private:
    
        // represents either Command or Connerctor
        std::string key;
        
        Node* parent;
        
        Node* left;
        
        Node* right;

    public:

    	Node(std::string);
    	
    	~Node();
    	
    	Node* getPar();
    	
    	Node* getLeft();
    	
    	Node* getRight();
    	
    	std::string getKey();

};

#endif // __NODE_H__

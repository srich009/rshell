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
    	
    	std::string getKey();

    	void setPar(Node* n);
    	
    	void setLeft(Node* n);
    	
    	void setRight(Node* n);
    	
    	Node* getPar();
    	
    	Node* getLeft();
    	
    	Node* getRight();

};

#endif // __NODE_H__
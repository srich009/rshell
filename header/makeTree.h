#ifndef __MAKETREE_H__
#define __MAKETREE_H__

#include <vector>

#include "node.h"
#include "object.h"

class Maketree
{

	public:
	
		Maketree();
		
		~Maketree();
		
		// create and return the syntax tree
		Node* build(std::vector<Object*>);

};

#endif // __MAKETREE_H__

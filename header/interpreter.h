#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__

#include <vector>
#include <string>

#include "object.h"
#include "command.h"
#include "connector.h"
#include "or.h"
#include "and.h"
#include "semiColon.h"
#include "node.h"
#include "leaf_cmd.h"
#include "block_cmd.h"

class Interpreter
{
    public:
        
        Node* parse(std::string s);
        
        void printTree(Node* n);
    
    private:
        
        bool isBalanced(std::string s); // refers to brackets, braces, parentheses...
        
        void postfix(std::vector<Object*> &v); // node reference so it works
        
        Node* buildTree(std::vector<Object*> v);
        
};

#endif // __INTERPRETER_H__

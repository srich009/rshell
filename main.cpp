// This is the main file for rshell

#include <iostream>
#include <string>

// JUST PUT ALL FOR NOW CHANGE LATER...
#include "header/action.h"
#include "header/and.h"
#include "header/command.h"
#include "header/connector.h"
#include "header/interpreter.h"
#include "header/line.h"
#include "header/makeTree.h"
#include "header/node.h"
#include "header/object.h"
#include "header/or.h"
#include "header/pattern.h"
#include "header/semiColon.h"

int main()
{
    std::string userInput = "";
    
    std::cout << "$ ";
    std::getline(std::cin, userInput);
    
    Interpreter* I = new Interpreter();
    I->parse(userInput);
    

    return 0;
}

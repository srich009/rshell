#include <iostream>
#include <string>
#include <vector>

#include "../header/object.h"
#include "../header/interpreter.h"

int main()
{
    std::string input;
    Interpreter* Inti = new Interpreter();
    std::vector<Object*> Vec;
    
    std::cout << "$ ";
    std::getline(std::cin, input);
    
    Vec = Inti->parse(input);
 
return 0;   
}

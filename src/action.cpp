#include "../header/action.h"

#include <cstdlib>  // exit
#include <iostream> // echo

void Action::exec(std::vector<Object*>)
{
    // just a stub so it compiles
}
//------------------------------------------------

void Action::exitr()
{
    exit(1); // ?? seems too simple...
}
//------------------------------------------------

bool Action::echo(std::string str)
{
    if(str.empty()) // if no str, then echo "\n"
    {
        std::cout << std::endl; 
    }
    else if(!str.empty())
    {
        std::cout << str;
        return true;
    }
    else
    {        
        std::cout << "echo(std::string) FAIL" << std::endl;
        return false;
    }
    return false; // catch all
}
//------------------------------------------------

bool Action::cd(std::string str)
{
    return false;
}
//------------------------------------------------

bool Action::pwd(std::string str)
{
    return false;
}
//------------------------------------------------


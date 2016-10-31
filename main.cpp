// This is the main file for rshell

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "stdio.h"
#include "unistd.h" // gethostname(), getlogin()
#include "errno.h"

// JUST PUT ALL FOR NOW CHANGE LATER...
#include "header/action.h"
#include "header/and.h"
#include "header/command.h"
#include "header/connector.h"
#include "header/interpreter.h"
#include "header/line.h"
#include "header/object.h"
#include "header/or.h"
#include "header/pattern.h"
#include "header/semiColon.h"

int main()
{
    // Get user && host 
    int flag = -1;       // flag will be set to 0 on success
    
    char loginName1[64] = {0}; // login buffer1
    flag = getlogin_r(loginName1, sizeof(loginName1));
    if(flag != 0)
    {
        perror("getlogin_r()"); // ERROR ?? No such Process ?? but buffer still gets some chars...
    }
    
    char * loginName2 = 0; // login buffer2, start NULL
    loginName2 = getlogin();  
    if(!loginName2)
    {
        perror("getlogin()"); // ERROR ?? No such File or Directory ?? NULL pointer...
    }
    
    char hostName[64];  // host buffer
    flag = gethostname(hostName, sizeof(hostName));
    if(flag != 0)
    {
        perror("gethostname()");
    }
    
    
    std::string userInput = ""; 
    
    do
    {
        std::cout << std::string(hostName) << "@";
        
        std::cout << "\n"; // temporary until resolve login error
        
        if(std::string(loginName1).empty())
        {std::cout << "loginName1 - FAIL" << "\n";}
        else
        {std::cout << std::string(loginName1) << "\n";} // ???? ERROR
        
        if(loginName2)
        {std::cout << std::string(loginName2) << "\n";} // ???? ERROR
        else
        {std::cout << "loginName2 - FAIL" << "\n";}
        
        std::cout << "$ ";
        std::getline(std::cin, userInput);    
        
        Pattern* P = new Pattern(userInput);
        P -> getI() -> parse( P -> getL() -> getString() ); // PARSE
        
        try
        {
             P -> getA() -> exec( P -> getL() -> getVec() ); // EXECUTE
        }
        catch(std::exception& e)
        {
            perror( e.what() ); // MAYBE CAHNGE ???
        }
    }
    while(1); // this should be changed later to terminate with special exit command
    
    
    return 0;
}

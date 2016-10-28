// This is the main file for rshell

#include <iostream>
#include <string>
#include <cstring>

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
//#include "header/makeTree.h"
//#include "header/node.h"

int main()
{
    // Get user && host 
    int flag = -1;      // flag will be set to 0 on success
    char hostName[64];  // host buffer
    char loginName[64]; // login buffer
    
    flag = getlogin_r(loginName, sizeof(loginName));
    if(flag != 0)
    {
        perror("getlogin_r()"); // ERROR ?? DOESNT EXIST ??
    }
    
    flag = gethostname(hostName, sizeof(hostName));
    if(flag != 0)
    {
        perror("gethostname()");
    }
    
    
    std::string userInput = ""; 
    
    //do
    {
        std::cout << std::string(hostName) << "@" << std::string(loginName);
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
            perror( e.what() ); // MAYBE CAHNGE .???
        }

    }
    //while(1);
    
    

    return 0;
}

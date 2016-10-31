// This is the main file for rshell

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#include <stdio.h>
#include <unistd.h> // gethostname(), getlogin()
#include <errno.h>
#include <sys/types.h>
#include <pwd.h>

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
    
    char userName[64] = "";
    flag = getlogin_r(userName, sizeof(userName)-1);
    if(flag != 0)
    {
        perror("getLogin_r()");
        strcpy(userName, "UNKNOWN");
    }
    
    char hostName[64];  // host buffer
    flag = gethostname(hostName, sizeof(hostName)-1);
    if(flag != 0)
    {
        perror("gethostname()");
    }
    
    std::string userInput = ""; 
    
    do
    {
        std::cout << std::string(userName) << "@";
        std::cout << std::string(hostName);
        
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

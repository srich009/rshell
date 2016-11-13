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
    // Get user name
    char userName[64] = ""; // user name buffer
    if(getlogin_r(userName, sizeof(userName)-1) != 0) // error returns nonzero
    {
        perror("getLogin_r()");
        strcpy(userName, "UNKNOWN_USER");
    }
    
    // Get host name
    char hostName[64];  // host name buffer
    if(gethostname(hostName, sizeof(hostName)-1) != 0) // error returns -1
    {
        perror("gethostname()");
        strcpy(hostName, "UNKNOWN_HOST");
    }
    
    std::string uName = std::string(userName);
    std::string hName = std::string(hostName);
    std::string userInput = ""; 
    
    do
    {
        std::cout << uName << "@" << hName << "$ "; // output prompt
        std::getline(std::cin, userInput);          // get user input 
        
        Pattern* P = new Pattern(userInput); // construct pattern
        
        // PARSE
        try
        {
            P -> getL() -> setRoot( P -> getI() -> parse( P -> getL() -> getString() ) ); // set root to parse return
        }
        catch(std::exception& e)
        {
            std::cout << "ERROR: PARSE" << std::endl;
            perror( e.what() );
        }            
        
        // EXECUTE
        try
        {
            //P->getI()->printTree(P->getL()->getRoot()); //prints tree
            P -> getA() -> exec( P -> getL() -> getRoot() ); // call exec function on root of tree
        }
        catch(std::exception& e)
        {
            std::cout << "ERROR: EXECUTE" << std::endl;
            perror( e.what() );
        }  
    }
    while(1); // terminate with special exit command
    
    return 0;
}

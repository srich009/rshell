#include "../header/action.h"
#include <stdexcept>
#include <stdio.h>
#include <cstdlib>  // exit
#include <iostream> // echo

void Action::exec(std::vector<Object*> o)
{
        bool b = true;
        for(unsigned i = 0; i < o.size(); i++)
        {
            
            if(o.at(i)->type() == "Command") //if its a command execute it
            {
                std::string com = o.at(i)->get(); //gets string
        
                std::string args = com.substr(com.find(" "), com.size()); //retrieves only the arguments(might not have anything)
            
                com = com.substr(0, com.find(" ")); //retrieves only the command
                
                //try
        
                if(com == "exit")
                {
                    exitr(); //might just use cstdlib exit
                }
                else if("cd")
                {
                    b = cd(args);
                }
                else if("pwd")
                {
                    b = pwd(args);
                }
                else if("echo")
                {
                    b = echo(args);
                }
                else
                {
                    //bin
                }
            }
            else //if it is a connector
            {
                if(o.at(i)->type() == "And" && b == false)
                {
                    i++;
                }
                else if(o.at(i)->type() == "Or" && b == true)
                {
                    i++;
                }
                else
                {
                    //do nothing if semicolon
                }
            }
        }
}
//------------------------------------------------

void Action::exitr()
{
    exit(0); // ?? seems too simple...
}
//------------------------------------------------

bool Action::echo(std::string str)
{
    if(str.empty()) // if no str, then echo "\n"
    {
        std::cout << std::endl;
        return true;
    }
    else if(!str.empty()) // HANDLE FLAGS HERE***
    {
                
        //if flag        
        // cut flag chunk out
        // std::string flag = ...
        // do flag (-n, -e, -E, --help, --version)
        
        // if flag == "-e" || "-E" , then special character stuff... modify string??
        
        // echo only str
        std::cout << str;
        
        // if flag != "-n" , then echo "\n" also
        
        return true;
    }
    else
    {        
        std::cout << "UNKNOWN echo(std::string) FAIL" << std::endl;
        return false;
    }
    return false; // catch all
}
//------------------------------------------------

bool Action::cd(std::string str)  // need to use: chdir(), opendir(), closedir()
{
    if(str.empty()) 
    {
        // // if no str, then cd ~/
        // return true;
    }
    else
    {
        // probably have a try catch block here
        
        // // if bad dir, then
        // std::cout << "rshell: cd: " << str << ": No such file or directory" << std::endl;
        // return false;
        
        // // else
        // change to correct directory
        
    }
    
    return false;
}
//------------------------------------------------

bool Action::pwd(std::string str)
{
    
    if(!str.empty())  //if flag, do flag (-L, -P, --help, --version)
    {
        // CATCH INVALID FLAGS
        if(str != "-L" || str != "--logical" || str != "-P" || str != "--physical"  || str != "--help" || str != "--version" )
        {
            std::cout << "rshell: pwd: " << str << ": invalid option" << std::endl;
            std::cout << "pwd: usage: pwd [-LP]" << std::endl;
            return false;
        }
        
        // do flag
        if(str == "-L" || str == "--logical")
        {
            // use PWD from environment, even if it contains symlinks
            // print to screen
            return true;
        }
        else if(str == "-P" || str == "--physical")
        {
            // avoid all symlinks
            // print to screen
            return true;
        }
        else if(str == "--help")
        {
            // display help && exit pwd
            return true;
        }
        else if( str == "--version")
        {
            // display version && exit pwd
            return true;
        }
        else
        {
            std::cout << "UNKNOWN FLAG ERROR" << std::endl;
            return false;
        }
    }
    
    // ELSE just print current working directory

    return true;
}
//------------------------------------------------


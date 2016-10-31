#include "../header/action.h"

#include <stdexcept>
#include <stdio.h>
#include <cstdlib>  // exit
#include <iostream> // echo
#include <unistd.h> // getcwd()
#include "sys/stat.h" // chdir()
#include "dirent.h" // closedir(), opendir()

void Action::exec(std::vector<Object*> o)
{
    bool b = true;
    for(unsigned i = 0; i < o.size(); i++)
    {
        
        if(o.at(i)->type() == "Command") //if its a command execute it
        {
            std::string com = o.at(i)->get(); //gets string
    
            std::string args = com.substr(com.find(" ") + 1, com.size()); //retrieves only the arguments(might not have anything)
        
            com = com.substr(0, com.find(" ") - 1); //retrieves only the command
            
            //try
    
            if(com == "exit")
            {
                exitr(); 
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
//-----------------------------------------------

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
    else if(!str.empty()) // NO HANDLE FLAGS HERE***
    {
        std::cout << str << std::endl;    
        return true;
    }
    else
    {        
        std::cout << "ERROR UNKNOWN echo(std::string) FAIL" << std::endl;
    }
    return false; // catch
}
//------------------------------------------------

bool Action::cd(std::string str)  // need to use: chdir(), opendir(), closedir()
{
    int flag = -1;
    char curDir[64]; // not sure about what size
    getcwd(curDir, sizeof(curDir)); // should return pointer to current working directory
    
    if(str.empty()) 
    {
        // if no str, then cd ~/
        std::string q = "~";
        flag = chdir(q.c_str());
        if(flag != 0)
        {
            perror("chdir()");
            return false;
        }
        return true;
    }
    else
    {
        if(str == std::string(curDir)) // fail if try to change to the directory already in
        {
            std::cout << "rshell: cd: " << str << ": No such file or directory" << std::endl;
            return false;
        }
        
        flag = chdir(str.c_str());
        
        if(flag != 0)
        {
            std::cout << "rshell: cd: " << str << ": No such file or directory" << std::endl;
            perror("chdir()");
            return false;
        }
        return true;
    }
    
    return false;
}
//------------------------------------------------

bool Action::pwd(std::string str)
{
    if(!str.empty())  // NO HANDLE FLAGS HERE***
    {
        std::cout << "ERROR UNKNOWN FLAG" << std::endl;
        return false;
    }
    
    char curDir[64]; // not sure about what size
    getcwd(curDir, sizeof(curDir)); // should return pointer to current working directory
    
    if(!curDir)
    {
        std::cout << "ERROR UNKNOWN PWD FAIL" << std::endl;
    }
    else
    {
        std::cout << std::string(curDir) << std::endl;
        return true;
    }
    return false; // catch
}
//------------------------------------------------


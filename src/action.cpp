#include "../header/action.h"
#include <stdexcept>
#include <stdio.h>
#include <cstdlib>  // exit
#include <iostream> // echo
#include <cstring>
#include <sys/wait.h>
#include <unistd.h>

void Action::exec(std::vector<Object*> o)
{
        bool b = true;
        for(unsigned i = 0; i < o.size(); i++)
        {
            
            if(o.at(i)->type() == "Command") //if its a command execute it
            {
                std::string com = o.at(i)->get(); //gets string literal
        
                std::string args = com.substr(com.find(" ") + 1, com.size()); //retrieves only the arguments(might not have anything)
            
                com = com.substr(0, com.find(" ") - 1); //retrieves only the command
                
                //try
        
                if(com == "exit")
                {
                    exitr(); //might just use cstdlib exit
                }
                else if(com == "cd")
                {
                    b = cd(args);
                }
                else if(com == "pwd")
                {
                    b = pwd(args);
                }
                else if(com == "echo")
                {
                    b = echo(args);
                }
                else
                {
                    //bin
                    std::string in = o.at(i)->get();
                    const char* in1 = in.c_str();
                    int flag = executr((char*)(in1));
                    if(flag == 1)
                    {
                        b = true;
                    }
                    else
                    {
                        false;
                    }
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

int Action::executr(char* cmd)
{
    char* argv[64];
    int flag = 0;
    char* tempC;
    unsigned c = 1;
    tempC = strtok(cmd, " ");
    argv[0] = tempC;
    
    while(tempC != NULL)
    {
        //cout << c << endl;
        tempC = strtok(NULL, " ");
        //cout << tempC << endl;
        argv[c] = tempC;
        //cout << argv[c] << endl;
        c++;
    }
    
    pid_t pid;
    pid_t wpid;
    
    int status;
    
    pid = fork();
    
    if(pid == 0) //if child
    {
        //cout << "in child first" << endl;
        flag = execvp(argv[0], argv);
        //cout << flag;
        //cout << "after execvp " << flag << endl;
        if(flag == -1) //attempt to execute but if -1 calls perror
        {
            //cout << flag << " in child (err)" << endl;
            std::string restring(argv[0]);
            perror(restring.c_str());
            exit(-1);
        }
        //cout << flag << " in child (norm)" << endl;
        exit(0);
    }
    else if (pid < 0)
    {
        perror("fork");
        exit(-1);
    }
    else
    {
        int i = 0;
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED); //waits on child and retrieves status
            //cout << status << " in parent process" << endl;
            i++;
        }
        while(!WIFEXITED(status) && !WIFSIGNALED(status)); //waits while child is not exited or killed by a signal
    }
    
    if(status != 0)
    {
        return -1;
    }
    
    return 1;
    
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


#include "../header/action.h"

#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>    
#include <iostream>   
#include <cstring>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

bool Action::exec(Node* n) // tree traversal algorithm
{
    if(n == 0) // error check NULL
    {        
        return false;       
    } 

    bool a = false; 
    bool b = false; 
    
    if(n != 0 && ( (n->getKey() != "&&") && (n->getKey() != "||") && ( n->getKey() != ";") ) ) // single
    {
        std::string in = n->getKey(); 
        
        if(in == "exit ") // builtin
        {
            exit(0); 
        }
        else if(in.substr(0, 5) == "test " || (in.at(0) == '[' && in.at(in.size()-2) == ']' )) // builtin
        {
            if( test(in) )
            {
                std::cout << "(True)" << std::endl;
                return true;
            }
            else
            {
                std::cout << "(False)" << std::endl;
                return false;
            }
        }
        else if(in.substr(0, 2) == "cd")
        {
            if(changeDir(in))
            {
                return true;
            }
            else
            {   std::string warning = "rshell: cd:" + in.substr(2, in.size());
                perror(warning.c_str());
                return false;
            }
        }
        else  // bin
        {        
            // implicit: convert( string ) -> convert (const char*) -> convert (char)
            if(executr((char*)(in.c_str())) == 1) 
            {
                return true;
            }
            // else
            return false;
        }
    }
    else // multi with connects
    {
        // recurse exec function part A
        a = exec(n->getLeft());
    
        // logic control flow for the  {"&&", "||", ";"}
        if(n->getKey().empty())
        {
            perror("ERROR: Missing connector");
            exit(1);
        }
        else // recurse exec function part B
        {            
            if(n->getKey() == "&&" && a == true) // &&
            {                
                b = exec(n->getRight());
            }
            else if(n->getKey() == "||" && a == false) // ||
            {               
                b = exec(n->getRight());
            }
            else if(n->getKey() == ";") // ;
            {  
                if(n->getRight() == 0){return a;} // ?? if is "cmd;"  where semi used as terminator
                b = exec(n->getRight());
            }
            
            return b;
            
        } //END: recursive solve  executr function part B
        
    } // END: multi with connects
    
    return false; // catch
}
//---------------------------------------------------------------


int Action::executr(char* cmd) // execute char[] with execvp syscalls
{
    char* argv[64];
    char* tempC;
    unsigned c = 1;
    
    tempC = strtok(cmd, " ");
    argv[0] = tempC;
    
    while(tempC != NULL)
    {
        tempC = strtok(NULL, " ");
        argv[c] = tempC;
        c++;
    }
    
    pid_t pid;
    pid_t wpid;
    
    int status;
    
    pid = fork(); // create child process
    
    if(pid == 0) //if child
    { 
        if(execvp(argv[0], argv) == -1) //attempt to execute but if -1 calls perror
        {
            std::string restring(argv[0]);
            perror(restring.c_str());
            exit(-1);
        }
        exit(0);
    }
    else if (pid < 0)
    {
        perror("fork");
        exit(-1);
    }
    else
    {
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED); //waits on child and retrieves status
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

bool Action::test(std::string str) // limited flags: -e, -d, -f
{
    std::string flag = "";
    struct stat buf;
    
    // PARSE OUT "test" || "[]"
    if(str.substr(0, 5) == "test ")
    {
        str = str.substr(4, str.size()-1);
        
        while(str.at(0) == ' ') // trim front space for flag
        {
            str = str.substr(1, str.size()-1);
        }
        
        while(str.at(str.size() - 1) == ' ') // trim back space for flag
        {
            str = str.substr(0, str.size()-1);
        }
    }
    else // []
    {
        str = str.substr(1, str.size()-1);
        str = str.substr(0, str.size()-2);
        
        while(str.at(0) == ' ') // trim front space for flag
        {
            str = str.substr(1, str.size()-1);
        }
        
        while(str.at(str.size() - 1) == ' ') // trim back space for flag
        {
            str = str.substr(0, str.size()-1);
        }
    }
    
    //CHECK FLAGS
    if(str.substr(0, 3) == "-e " || str.substr(0, 3) == "-f " || str.substr(0, 3) == "-d " )
    {
        flag = str.substr(0, 2);
        str = str.substr(3, str.size()-1);
    }
    else if(str.at(0) == '-')
    {
        std::cout << "ERROR: bad flag value" << std::endl;
        return false;
    }
    else
    {
        flag = "-e";
    }
    
    // HANDLE FLAGS
    if(flag == "-e") // -e
    {
        if(stat(str.c_str(), &buf) == 0)
        {
            return true;
        }
    }
    else if(flag == "-f" ) // -f 
    {
        if(stat(str.c_str(), &buf) == 0)
        {
            if(S_ISREG (buf.st_mode & S_IFMT))
            {
                return true;
            }
        }
    }
    else if(flag == "-d" ) // -d
    {
        if(stat(str.c_str(), &buf) == 0 )
        {
            if(S_ISDIR (buf.st_mode & S_IFMT))
            {
                return true;
            }
        }
    }
    
    return false; // catch
}
//---------------------------------------------------------------

bool Action::changeDir(std::string dir)
{
    char* oldPath;
    oldPath = getenv("PWD");

    int n = 0;
    
    if(dir == "cd ")
    {
        char* home;
        home = getenv("HOME");
        n = chdir(home);
        if(n < 0)
        {
            return false;
        }
        
    }
    else if(dir == "cd - ")
    {
        char* oldEnv;
        oldEnv = getenv("OLDPWD");
        std::cout << oldEnv << std::endl;
        n = chdir(oldEnv);
        if(n < 0)
        {
            return false;
        }
    }
    else
    {
        dir = dir.substr(3, dir.size() - 4);
        n = chdir(dir.c_str());
        if(n < 0)
        {
            return false;
        }
    }
    
    char path [FILENAME_MAX];
    char* returnHolder;
    returnHolder = getcwd(path, FILENAME_MAX);

    n = setenv("PWD", path, 1);
    if(n < 0)
    {
        return false;
    }
    
    n = setenv("OLDPWD", oldPath, 1);
    if(n < 0)
    {
        return false;
    }
    
    return true;
}
//---------------------------------------------------------------
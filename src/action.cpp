#include "../header/action.h"

#include <stdexcept>
#include <stdio.h>
#include <cstdlib>    
#include <iostream>   
#include <cstring>
#include <sys/wait.h>
#include <unistd.h>

void Action::exec(Node* n)
{
    // PREFIX tree traversal algorithm
    
    if(n == 0) // error check
    {        
        std::cout << "ERROR: NULL Node* passed to exec" << std::endl;
        return;       
    }

    
    // psuedo code ... 
    /*
    
        let T be root node tree;
        
        if(T != NULL)
        {
            return t.value;
        }
        
        // recursive solve   // solve is executr function ?
        A = solve.(t->left);
        B = solve(t->right);
        
        // calculate and apply the operator "T.value" to A and B, return result/error
        try
        {
            calculate(A, B, T.value); // calculate handles logic control flow {"&&", "||", ";"}
            return;
        }
        catch(std::exception &e)
        {
            cout << e.what() << endl;
            exit(1);
        }
        
        
    */
    
      
    
}
//---------------------------------------------------------------

int Action::executr(char* cmd)
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
        if(-1 == execvp(argv[0], argv)) //attempt to execute but if -1 calls perror
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
        int i = 0;
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED); //waits on child and retrieves status
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

/// OLD VERSION OF EXEC

    // bool b = true;
    
    // for(unsigned i = 0; i < o.size(); i++)
    // {
    //     if(o.at(i)->type() == "Command")      //if its a command execute it
    //     {            
    //         std::string com = o.at(i)->get(); //gets string literal
    
    //         if(com == "exit ")
    //         {
    //             exit(0); 
    //         }
    //         // else if(com == "cd ") // NOT USED
    //         // {
    //         //     b = cd(args);
    //         // }
    //         else
    //         {
    //             //bin
    //             std::string in = o.at(i)->get();
    //             const char* in1 = in.c_str();
    //             int flag = executr((char*)(in1));
    //             if(flag == 1)
    //             {
    //                 b = true;
    //             }
    //             else
    //             {
    //                 b = false;
    //             }
    //         }
    //     }
    //     else //if it is a connector
    //     {            
    //         if(o.at(i)->type() == "And" && b == false)
    //         {
    //             i++;
    //         }
    //         else if(o.at(i)->type() == "Or" && b == true)
    //         {
    //             i++;
    //         }
    //         else
    //         {
    //             //do nothing if semicolon
    //         }
    //     }
    // }
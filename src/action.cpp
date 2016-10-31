#include "../header/action.h"
#include <stdexcept>
#include <stdio.h>

Action::exec(std::vector<Object*> o)
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
}
#include "../header/interpreter.h"

#include <cstring> //library for strtok
#include <iostream> 

std::vector<Object*> Interpreter::parse(std::string s)
{
    // REMOVE_COMMENTS
    //================================================================
    unsigned int pos = s.find("#"); // location of '#'
    
    if(pos != std::string::npos)    // if the position returned exists in the string
    {
        s = s.substr(0, pos);       // set it equal to a substring of itself to the position
    }
    //=================================================================
    
    
    // REMOVE_SPACES
    //=================================================================
    // convert string, .c_str() returns const* char
    const char* s_char_ = s.c_str();

    // VERY BAD
    // use C-style cast from const char* to char*
    char* tempC = strtok((char*)(s_char_), " "); //temp char array to store tokens
    
    std::vector<std::string> sholder; // vector for tokens
    
    while(tempC != NULL) // while loop to extract tokens until none left
    {
        //use string constructor to package char array, push_back in vector
        sholder.push_back(std::string(tempC));
        
        tempC = strtok(NULL, " "); // extract next token
    }    
    //======================================================================
    
    
    // HANDLE_SEMICOLON
    //==================================================================
    for(unsigned i = 0; i < sholder.size(); i++)
    {
        // last is semicolon
        if( (sholder.at(i)).at(sholder.at(i).size() -1) == ';' )
        {
            std::string temp = ";";
            std::vector<std::string>::iterator it = sholder.begin() + (i + 1); // iterator to next past "x;"
            sholder.at(i) = sholder.at(i).substr(0, sholder.at(i).size() - 1); // remove ';' from string
            sholder.insert( it , temp ); // insert new ';' string
            i++; // prevent infinte loop
        }
    }    
    //==================================================================
    
    
    // REJOIN COMMANDS TO THEIR ARGS && SEPARATE WITH CONNECTORS
    //==================================================================
    // vector of Object pointers, represents commands joined with their arguments separated by connectors
    std::vector<Object*> final_form;
    
    std::string tempString; //for each iteration, puts together command and args and pushes
    
    // WW 
    for(unsigned i = 0; i < sholder.size(); i++)
    {
        
        bool semiBool = (sholder.at(i) == ";"); //checks if the current string is a connector
        bool andBool = (sholder.at(i) == "&&");
        bool orBool = (sholder.at(i) == "||");
        
        // XX
        if(semiBool || andBool || orBool) 
        {
            final_form.push_back(new Command(tempString)); // push command to vector
            
            if(semiBool)
            {                
                final_form.push_back(new Semicolon("; "));
            }
            else if(andBool)
            {
                final_form.push_back(new And("&& "));
            }
            else
            {
                final_form.push_back(new Or("|| "));
            }
            tempString.clear();
        }
        else
        {
            tempString += sholder.at(i);
            
            if(tempString.at(tempString.size() - 1) != ' ') // prevent double space error
            {
                tempString += " ";
            }
        } 
        // XX
        
        // YY
        if(i + 1 == sholder.size()) 
        {
            if(tempString != "")
            {
                final_form.push_back(new Command(tempString)); // get the last part
            }
        } 
        // YY
        
    }// WW
    
    return final_form;   // final ordering of the parsed text. 
}

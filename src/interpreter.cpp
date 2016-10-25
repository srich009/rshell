#include "../header/interpreter.h"

#include <cstring> //library for strtok

// THIS IS FOR TESTING, REMOVE LATER!!!  ***********************************
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
    
    
    // THIS IS FOR TESTING, REMOVE LATER!!!  ***********************************
    // /*
    // check to see if parsed out spaces correctly
    for(unsigned i = 0; i < sholder.size(); i++)
    {
        std::cout << "\""<< sholder.at(i) << "\" ";
    }    
    std::cout << std::endl;
    // */
    
    
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
    
    
    // THIS IS FOR TESTING, REMOVE LATER!!!  ***********************************
    // /*
    // check to see if parsed ';' correctly
    for(unsigned i = 0; i < sholder.size(); i++)
    {
        std::cout << "\""<< sholder.at(i) << "\" ";
    }    
    std::cout << std::endl;
    // */
    
    
    // next step is putting the commands and args together as well as pushing it into object
    
    //============READ THE FOLLOWING WALL OF TEXT===============
    
    //what the following algorithm should do is there should be a vector of strings
    //declared outside of the for loop which commands and their args can be added to
    //and once a connector has been found, the vector of strings with the commands and
    //args should be constructed into an Object and pushed back into a vector of Object
    //pointers. After that, the vector of strings will be cleared so that we can
    //put the found connector into it and construct it into an Object and push it
    //back too. Next we will clear the vector of strings so we can push back the
    //next string to start a new vector of commands and args in the next iteration.
    //This algorithm should work because Crites told us that the input will be appended
    //by a semicolon and so there shouldn't be any left over unpushed string of vectors
    //
    //
    //Problem: we cannot allocate memory for Object so we cannot return a pointer
    //Potential Solution: we can allocate the specific subclass using their foundBools
    //
    //Problem: 
    
    std::vector<Object*> final_form;
    
    std::string tempString; //for each iteration, puts together command and args and pushes
        
    for(unsigned i = 0; i < sholder.size(); i++)
    {
        
        bool semiBool = (sholder.at(i) == ";"); //checks if the current string is a connector
        bool andBool = (sholder.at(i) == "&&");
        bool orBool = (sholder.at(i) == "||");
        
        if(semiBool || andBool || orBool)
        {
            final_form.push_back(new Command(tempString));
            
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
        }
        else
        {
            tempString += sholder.at(i);
            tempString += " ";
        }
    }
    
    
        
    // THIS IS FOR TESTING, REMOVE LATER!!!  ***********************************
    // /*
    // check to see if rejoined correctly
    for(unsigned i = 0; i < final_form.size(); i++)
    {
        std::cout << "\""<< final_form.at(i)->get() << "\" ";
    }    
    std::cout << std::endl;
    
    return final_form;    
}

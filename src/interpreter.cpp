#include "../header/interpreter.h"
#include <sstream>
#include <cstring> //library for strtok
#include <iostream> 
#include <cstdlib>
#include <stack>

Node* Interpreter::parse(std::string s)
{
    
    if(s == "")
    {
        return 0;
    }
    // REMOVE_COMMENTS
    //================================================================
    unsigned int pos = s.find("#"); // location of '#'
    
    if(pos != std::string::npos)    // if the position returned exists in the string
    {
        s = s.substr(0, pos);       // set it equal to a substring of itself to the position
    }
    //=================================================================
    
    // check if ballanced [] && ()
    //================================================================
    if(!isBalanced(s))
    {
        std::cout << "ERROR: not ballanced () OR []" << std::endl;
        return 0; // NULL Node*
    }
    //================================================================
    
    
    ///****************** HEY HEY HEY *****************************************************
    
    std::vector<std::string> str_vec;
    std::istringstream iss(s);
    std::string temp;
    int lefnum = 0;
    int rightnum = 0;

    while(iss >> temp)
    {
        if(temp.find("(") != std::string::npos)
        {
            for(unsigned i = 0; i < temp.size(); i++)
            {
                if(temp.at(i) == '(')
                {
                    lefnum++;
                }
                else if(temp.at(i) == ')')
                {
                    rightnum++;
                }
            }
            std::string ntemp;
            temp += " ";
            while(iss >> ntemp)
            {
                for(unsigned i = 0; i < ntemp.size(); i++)
                {
                    if(ntemp.at(i) == '(')
                    {
                        lefnum++;
                    }
                    else if(ntemp.at(i) == ')')
                    {
                        rightnum++;
                    }
                }
                temp += ntemp;
                if(lefnum != rightnum)
                {
                    temp = temp + " ";
                }
                else
                {
                    break;
                }
            }
            //temp.erase(temp.begin() + temp.find('(')); COME BACK HERE IF YOU FUCK UP
            //temp.erase(temp.begin() + temp.find_last_of(')'));
            lefnum = 0;
            rightnum = 0;
        }
        
        str_vec.push_back(temp);
    }
    
    /*for(unsigned j = 0; j < str_vec.size(); j++)
    {
        std::cout << str_vec.at(j) << std::endl;
    }*/

    // str_vec = to the return val from new parse function
    // parse each string in the vector individually
    
    ///***********************************************************************
    
    if(str_vec.at(0) == ";" || str_vec.at(0) == "&&" || str_vec.at(0) == "||")
    {
        std::cout << "ERROR: Leading with connector" << std::endl;
        return 0;
    }
    
    // HANDLE_SEMICOLON
    //==================================================================
    for(unsigned i = 0; i < str_vec.size(); i++)
    {
        // last is semicolon
        if( (str_vec.at(i)).at(str_vec.at(i).size() -1) == ';' )
        {
            std::string temp1 = ";";
            std::vector<std::string>::iterator it = str_vec.begin() + (i + 1); // iterator to next past "x;"
            //std::cout << str_vec.at(i).substr(0, str_vec.at(i).size() - 1) << std::endl;
            str_vec.at(i) = str_vec.at(i).substr(0, str_vec.at(i).size() - 1); // remove ';' from string
            //std::cout << temp1 << std::endl;
            str_vec.insert( it , temp1 ); // insert new ';' string
            i++; // prevent infinte loop
        }
    }    
    //==================================================================
    /*std::cout << "round 2" << std::endl;
    for(unsigned j = 0; j < str_vec.size(); j++)
    {
        std::cout << str_vec.at(j) << std::endl;
    }*/
    
    // REJOIN COMMANDS TO THEIR ARGS && SEPARATE WITH CONNECTORS
    //==================================================================
    std::vector<Object*> final_form; // vector of Object pointers, commands joined with their arguments separated by connectors
    std::string tempString;          // for each iteration, puts together command and args and pushes
    
    // WW 
    for(unsigned i = 0; i < str_vec.size(); i++)
    {
        bool semiBool = (str_vec.at(i) == ";"); //checks if the current string is a connector
        bool andBool = (str_vec.at(i) == "&&");
        bool orBool = (str_vec.at(i) == "||");
        bool blockBool = (str_vec.at(i).find("(") != std::string::npos);
        
        // XX
        if(semiBool || andBool || orBool || blockBool) 
        {
            final_form.push_back(new Leaf(tempString)); // push command to vector
            
            if(semiBool)
            {                
                final_form.push_back(new Semicolon(";"));
            }
            else if(andBool)
            {
                final_form.push_back(new And("&&"));
            }
            else if(orBool)
            {
                final_form.push_back(new Or("||"));
            }
            else if(blockBool)
            {
                str_vec.at(i).erase(str_vec.at(i).begin() + str_vec.at(i).find('('));
                str_vec.at(i).erase(str_vec.at(i).begin() + str_vec.at(i).find_last_of(')'));
                final_form.push_back(new Block(str_vec.at(i)));
            }
            tempString.clear();
        }
        else
        {
            tempString += str_vec.at(i);
            
            if(tempString.at(tempString.size() - 1) != ' ') // prevent double space error
            {
                tempString += " ";
            }
        } 
        // XX
        
        // YY
        if(i + 1 == str_vec.size()) 
        {
            if(tempString != "")
            {
                final_form.push_back(new Leaf(tempString)); // get the last part
            }
        } 
        // YY
        
    }// WW
    
    //std::cout << "inside parse (before remove space)" << std::endl;
    
        
    // THIS IS FOR TESTING, REMOVE LATER!!!  ***********************************
    // check to see if rejoined correctly
    /*for(unsigned i = 0; i < final_form.size(); i++)
    {
        std::cout << "\""<< final_form.at(i)->get() << "\" ";
    }    
    std::cout << std::endl;  */  
    
    for(unsigned i = 0; i < final_form.size(); i++)
    {
        if(final_form.at(i)->get() == "")
        {
            final_form.erase(final_form.begin() + i);
        }
    }
    
    //std::cout << "inside parse (after remove space)" << std::endl;
    
        
    // THIS IS FOR TESTING, REMOVE LATER!!!  ***********************************
    // check to see if rejoined correctly
    /*for(unsigned i = 0; i < final_form.size(); i++)
    {
        std::cout << "\""<< final_form.at(i)->get() << "\" ";
    }    
    std::cout << std::endl;  */
    
    //build root of the tree
    //==========================================================================
    Node* n = 0; // init as NULL
    postfix(final_form);
    n = buildTree(final_form);
    //printTree(n);
    //==========================================================================
    
    return n; // root of tree
}
//-------------------------------------------------------------------------------------------


bool Interpreter::isBalanced(std::string s) // check for ballanced number of separators (, [
{
    std::stack<char> stk;
    
    for(std::string::iterator it = s.begin(); it != s.end(); it++)
    {
        if(*it == '(' || *it == '[')
        {
            stk.push(*it);
        }
        else if(*it == ')' || *it == ']' )
        {
            if(stk.empty())
            {
                return false;
            }
            else
            {
                if(*it == ')' && stk.top() != '(' )
                {
                    return false;
                }
                else if(*it == ']' && stk.top() != '[' )
                {
                    return false;
                }
                else
                {
                    stk.pop();
                }
            } 
        }
    }
    
    return stk.empty();
}
//-------------------------------------------------------------------------------------------


void Interpreter::postfix(std::vector<Object*> &v)
{
   /*std::cout << "inside postfix (beginning)" << std::endl;
    
        
    // THIS IS FOR TESTING, REMOVE LATER!!!  ***********************************
    // check to see if rejoined correctly
    for(unsigned i = 0; i < v.size(); i++)
    {
        std::cout << "\""<< v.at(i)->get() << "\" ";
    }    
    std::cout << std::endl;    */
    // THIS IS FOR TESTING, REMOVE LATER!!!  ***********************************

    
    std::stack<Object*> s;
    unsigned i = 0;
    std::vector<Object*> pfix;
    
    while(i < v.size())
    {
        if(v.at(i)->type() == "Leaf" || v.at(i)->type() == "Block")
        {
            pfix.push_back(v.at(i));
        }
        else
        {
            if(s.empty())
            {
                s.push(v.at(i));
            }
            else
            {
                while(!s.empty())
                {
                    pfix.push_back(s.top());
                    s.pop();
                }
                s.push(v.at(i));
            }
        }
        i++;
    }
    
    while(!s.empty())
    {
        pfix.push_back(s.top());
        s.pop();
    }
    
    v = pfix;
    
    // THIS IS FOR TESTING, REMOVE LATER!!!  ***********************************
    // check to see if rejoined correctly
    /*for(unsigned i = 0; i < v.size(); i++)
    {
        std::cout << "\""<< v.at(i)->get() << "\" ";
    }    
    std::cout << std::endl;*/
    // THIS IS FOR TESTING, REMOVE LATER!!!  ***********************************
}
//-------------------------------------------------------------------------------------------
//"ls" ";"
Node* Interpreter::buildTree(std::vector<Object*> v)
{
    std::stack<Node*> s;
    Node* o;
    Node* o1;
    Node* o2;
    
    for(unsigned i = 0; i < v.size(); i++)
    {
        if(v.at(i)->type() == "Leaf")
        {
            o = new Node(v.at(i)->get());
            s.push(o);
        }
        else if(v.at(i)->type() == "Block")
        {
            o = parse(v.at(i)->get());
            s.push(o);
        }
        else
        {
            if(s.empty())
            {
                
            }
            else{
                

                o = new Node(v.at(i)->get());
                if(s.size() >= 2)
                {
                    o1 = s.top();
                    s.pop();
                    o2 = s.top();
                    s.pop();
                    
                o->setRight(o1);
                o1->setPar(o);
                o->setLeft(o2);
                o2->setPar(o);
                
                s.push(o);
                }
            }
        }
    }
    
    o = s.top();
    s.pop();
    
    
    return o;
}
//------------------------------------------------------------

void Interpreter::printTree(Node* n)
{
    if(n != 0)
    {
        printTree(n->getLeft());
        /*if(n->getLeft() == 0 && n->getRight() == 0)
        {
            std::cout << "leaf: ";
        }*/
        std::cout << "current node: " <<n->getKey(); 
                if(n->getPar() > 0)
        {
            std::cout << " parent: " << n->getPar()->getKey();
        }
        std::cout << std::endl;
        printTree(n->getRight());
    }

}
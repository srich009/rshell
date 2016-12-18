#include "../header/interpreter.h"

#include <sstream>
#include <cstring> //library for strtok
#include <iostream> 
#include <cstdlib>
#include <stack>

Node* Interpreter::parse(std::string s)
{
    // CATCH EMPTY
    //==============
    if(s.empty())
    {return 0;}
    //==============
        
    // REMOVE_COMMENTS
    //================================================================
    unsigned int pos = s.find("#"); // location of '#'
    
    if(pos != std::string::npos)    // if the position returned exists in the string
    {
        s = s.substr(0, pos);       // set it equal to a substring of itself to the position
    }
    //=================================================================
    
    // CHECK FOR BALLANCED [] && ()
    //================================================================
    if(!isBalanced(s))
    {
        std::cout << "ERROR: not ballanced () OR []" << std::endl;
        return 0; // NULL Node*
    }
    //================================================================
    
    // PARSE PARENTHESES && HANDLE PRECEDENCE
    //==================================================================
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

            lefnum = 0;
            rightnum = 0;
        }

        str_vec.push_back(temp);
    }

    // str_vec = to the return val from new parse function
    // parse each string in the vector individually
    //===================================================================
    
    //SYNTAX CHECK (leading connector/empty vector)
    //===================================================================
    if(!str_vec.empty())
    {
        if(str_vec.at(0) == ";" || str_vec.at(0) == "&&" || str_vec.at(0) == "||")
        {
            std::cout << "ERROR: Leading with connector" << std::endl;
            return 0;
        }
    }
    else
    {
        std::cout << "ERROR: Empty argument" <<std::endl;
        return 0; // empty vector == no commands... ex. input = "()"
    }
    //===================================================================
        
    // HANDLE_SEMICOLON
    //==================================================================
    for(unsigned i = 0; i < str_vec.size(); i++)
    {
        // last is semicolon
        if( (str_vec.at(i)).at(str_vec.at(i).size() -1) == ';' )
        {
            std::vector<std::string>::iterator it = str_vec.begin() + (i + 1); // iterator to next string after "cur;"
            str_vec.at(i) = str_vec.at(i).substr(0, str_vec.at(i).size() - 1); // remove ';' from string
            str_vec.insert( it , ";" ); // insert new ";" string into vector
            i++; // prevent infinte loop
        }
    }    
    //==================================================================
        
    // REJOIN COMMANDS TO THEIR ARGS && SEPARATE WITH CONNECTORS
    //==================================================================
    std::vector<Object*> final_form; // vector of Object pointers, commands joined with their arguments separated by connectors
    std::string tempString;          // for each iteration, puts together command and args and pushes
    
    // xx
    for(unsigned i = 0; i < str_vec.size(); i++)
    {
        bool semiBool = (str_vec.at(i) == ";"); //checks if the current string is a connector
        bool andBool = (str_vec.at(i) == "&&");
        bool orBool = (str_vec.at(i) == "||");
        bool blockBool = (str_vec.at(i).find("(") != std::string::npos);
        
        // yy
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
        // yy
        
        // zz
        if(i + 1 == str_vec.size()) 
        {
            if(tempString != "")
            {
                final_form.push_back(new Leaf(tempString)); // get the last part
            }
        } 
        // zz
        
    }// xx
    //========================================================================== 
 
/*std::cout << "BEFORE" << '\n';
for(unsigned i = 0; i < final_form.size(); i++)
{
    std::cout << i << ": " << "\""<< final_form.at(i)->get() << "\" " << std::endl;
}  
std::cout << '\n';*/
 
    // ERASE ANY NULL OBJECTS
    //==========================================================================    
    for(unsigned i = 0; i < final_form.size(); i++) 
    {
        if(final_form.at(i)->get() == "")
        {
            final_form.erase(final_form.begin() + i);
        }
    }
    //==========================================================================
    
/*std::cout << "AFTER" << '\n';
for(unsigned i = 0; i < final_form.size(); i++)
{
    std::cout << i << ": " << "\""<< final_form.at(i)->get() << "\" " << std::endl;
}    
std::cout << '\n';*/
        
    // BUILD ROOT OF TREE
    //==========================================================================
    Node* n = 0;                // init pointer as NULL
    postfix(final_form);        // convert vector from infix to postfix
    
/*std::cout << "postfix" << '\n';
for(unsigned i = 0; i < final_form.size(); i++)
{
    std::cout << i << ": " << "\""<< final_form.at(i)->get() << "\" " << std::endl;
}    
std::cout << '\n';*/
    
    n = buildTree(final_form);  // construct tree with stack from postfix tokens
    //==========================================================================
    
    return n; // root
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
}
//-------------------------------------------------------------------------------------------


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
            if(!s.empty()) // empty == do nothing
            {
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
//---------------------------------------------------------------
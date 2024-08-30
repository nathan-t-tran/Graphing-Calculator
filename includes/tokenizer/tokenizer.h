#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <iostream>
#include "../../includes/token/token.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"
#include <string.h>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>

using namespace std;

class Tokenizer
{
public:
    Tokenizer(string eq) //Gets equation string.
    {
        _equation = eq; //Stores given equation into local var.
    }

    bool isNumeric(std::string const &str)      //checks for numbers.
    {
        auto it = str.begin();
        while (it != str.end() && std::isdigit(*it)) {
            it++;
        }
        return !str.empty() && it == str.end();
    }

    Queue<Token*> infix_me()
    {
        //cout << "TOKENIZER: INFIXING STRING" << endl;
        //Initializes variables
        Queue<Token*> infix;
        string myEquation = _equation;
        vector<string> tokens;

        //Separates string into tokens
        istringstream iss(myEquation);
        string s;
        while (iss >> s) {
            tokens.push_back(s);
        }
    
        for (const string &s: tokens) 
        {
            //cout << s << endl;
            if (isNumeric(s))
            {
                //cout << "I AM PUSHING A NUMBER: " << s << endl;
                infix.push(new Integer(s));
                //cout << infix << endl;
            }

            if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^")
            {
                //cout << "I AM PUSHING AN OPERATOR: " << s << endl;
                infix.push(new Operator(s));
            }

            if (s == "x" || s == "X" || s == "sin" || s == "tan" || s == "cos" || s == "csc" || s == "sec" || s == "cot" || s == "abs" || s == "log")
            {
                //cout << "I AM PUSHING A FUNCTION: " << s << endl;
                infix.push(new Function(s));
            }

            //cout << infix << endl;
            //cout << "TOKENIZER: INFIXED STRING" << endl;
        }
        return infix;
    }
private:
    string _equation;
};

#endif
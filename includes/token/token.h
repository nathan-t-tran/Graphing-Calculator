#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
//#include "constants.h"

using namespace std;

class Token
{
public:
    Token():_tk_str("UNINITIALZED"), _type(-1){}; 
    Token(string Tok_str, int type): _tk_str(Tok_str), _type(type){}; 

    friend ostream& operator <<(ostream& outs, const Token& token) {
        token.Print(outs); 
        return outs; 
    }

    virtual void Print(ostream& outs=cout) const{
        outs<<"<"<<_tk_str<<">"; 
    }

    int TypeOf(){return _type;}
    string TkStr(){return _tk_str;}
    private: 
    string _tk_str; 
    int _type; 


};

#endif // TOKEN_H
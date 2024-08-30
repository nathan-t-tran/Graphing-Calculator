#ifndef INTEGER_H
#define INTEGER_H
#include "token.h"

class Integer: public Token{
public:
    Integer(double num):Token(to_string(num), 1), _num(num){};
    Integer(string num):Token(num, 1),_num(atof(num.c_str())){};
    void Print(ostream& outs){
        outs<<'['<<_num<<']';
    }
    double Num(){return _num;}
private:
    double _num;
};



#endif
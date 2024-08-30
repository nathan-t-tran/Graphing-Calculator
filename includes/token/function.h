#ifndef FUNCTION_H
#define FUNCTION_H
#include "operator.h"

using namespace std;

class Function: public Operator{
public:
    Function(string func):Operator (func){
        _func = func;
    }
    string func(){return _func;}

private:
    string _func;
};

#endif
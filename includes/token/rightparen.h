#ifndef RIGHTPAREN_H
#define RIGHTPAREN_H

using namespace std;

class RightParen: public Token{
public:
    RightParen():Token(")", 4)
    {
        _rightparen = ")";
    }
    string rightparen(){return _rightparen;}
private:
    string _rightparen;
};

#endif
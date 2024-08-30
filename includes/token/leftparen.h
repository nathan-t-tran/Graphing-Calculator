#ifndef LEFTPAREN_H
#define LEFTPAREN_H

using namespace std;

class LeftParen: public Token{
public:
    LeftParen():Token("(", 3)
    {
        _leftparen = "(";
    }
    string leftparen(){return _leftparen;}

private:
    string _leftparen;
};

#endif
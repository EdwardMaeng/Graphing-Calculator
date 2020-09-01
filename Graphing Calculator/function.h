#ifndef FUNCTION_H
#define FUNCTION_H

#include "token.h"

class Function : public Token {
public:
    Function(string f);
    int prec();
    string Func();
    int getType();
    void print() const;

private:
    string _f;
    int _precedence;
};

#endif // FUNCTION_H

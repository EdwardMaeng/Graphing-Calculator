#ifndef LPAREN_H
#define LPAREN_H

#include "token.h"

class Lparen : public Token {
public:
    Lparen(string l);
    string lpar();
    int prec();
    int getType();
    void print() const;

private:
    string _l;
    int _precendence;
};

#endif // LPAREN_H

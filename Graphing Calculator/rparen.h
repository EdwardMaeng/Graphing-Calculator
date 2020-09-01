#ifndef RPAREN_H
#define RPAREN_H

#include "token.h"

class Rparen : public Token {
public:
    Rparen(string r);
    string rpar();
    int prec();
    int getType();
    void print() const;

private:
    string _r;
    int _precendece;
};

#endif // RPAREN_H

#ifndef OPERATOR_H
#define OPERATOR_H

#include "token.h"

class Operator : public Token {
public:
    Operator(string op);
    int prec();
    string OP();
    int getType();
    void print() const;

private:
    string _op;
    int _precedence;
};

#endif // OPERATOR_H

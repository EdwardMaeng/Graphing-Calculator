#ifndef VARIABLE_H
#define VARIABLE_H

#include "token.h"

class Variable : public Token {
public:
    Variable(string v);
    string var();
    int getType();
    void print() const;

private:
    string _v;
};

#endif // VARIABLE_H

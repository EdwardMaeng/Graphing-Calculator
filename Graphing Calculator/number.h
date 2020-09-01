#ifndef NUMBER_H
#define NUMBER_H

#include "token.h"

class Number : public Token {
public:
    Number(string num);
    double num();
    string n();
    int getType();
    void print() const;

private:
    double _num;
    string _n;
};

#endif // NUMBER_H

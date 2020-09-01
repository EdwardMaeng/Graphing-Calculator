#ifndef EVALUATE_H
#define EVALUATE_H

#include "rpn.h"
#include "shunting_yard.h"

class Evaluate {
public:
    Evaluate();
    Evaluate(string exp);
    double eval(double value);

private:
    Queue<Token*> _infix;
    Queue<Token*> _postfix;
    string _exp;
};

#endif // EVALUATE_H

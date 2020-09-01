#ifndef RPN_H
#define RPN_H

#include "token.h"
#include "number.h"
#include "operator.h"
#include "variable.h"
#include "function.h"

class RPN {
public:
    RPN(Queue<Token*> input);
    RPN(string input_str);
    double rpn(double value);

private:
    Queue<Token*> _q;
};

#endif // RPN_H

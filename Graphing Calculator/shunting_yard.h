#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include "token.h"
#include "number.h"
#include "operator.h"
#include "lparen.h"
#include "rparen.h"
#include "function.h"

class Shunting_Yard {
public:
    Shunting_Yard(Queue<Token*> infix);
    Queue<Token*> postfix();

private:
    Queue<Token*> _infix;
    Queue<Token*> _postfix;
};

#endif // SHUNTING_YARD_H

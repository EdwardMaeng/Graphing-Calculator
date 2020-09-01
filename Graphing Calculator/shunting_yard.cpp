#include "shunting_yard.h"

Shunting_Yard::Shunting_Yard(Queue<Token*> infix) : _infix(infix), _postfix() {

}

/*
 * Shunting Yard:
 * It changes an infix notation to postfix notation. (ex. 3 + 5 to 3 5 +). A poped queue of type number,
 * variable, and left paren simply gets pushed into postfix queue. A type right paren loops through the temp
 * stack (this is for operators / functions) until it finds left paren and pushes into the postfix queue.
 * A type operator checks the top of temp stack (precedence) and pushes into postfix queue if the top of temp stack
 * is greater than the infix pop. A type function works similarly like the the operator, however,
 *
 */

Queue<Token*> Shunting_Yard::postfix() {
    Token* p;
    Stack<Token*> temp;

    while(_infix.size() > 0) {
        p = _infix.pop();
        int type = p->getType();

        switch(type) {
        case NUMBER: {
            _postfix.push(p);
            break;
        }
        case VARIABLE: {
            _postfix.push(p);
            break;
        }
        case LPAREN: {
            temp.push(p);
            break;
        }
        case RPAREN: {
            Token* l = *temp.top();
            while(temp.size() > 0) {
                if(l->getType() != LPAREN) {
                    _postfix.push(temp.pop());
                    if(temp.size() > 0) {
                        l = *temp.top();
                    }
                }
                else if(l->getType() == LPAREN) {
                    temp.pop();
                    break;
                }
            }
            break;
        }
        case OPERATOR: {
            Operator* op = static_cast<Operator*>(p);
            if(temp.empty()) {
                temp.push(p);
            }
            else {
                Token* s = *temp.top();
                Operator* s_top = static_cast<Operator*>(s);
                while(temp.size() > 0) {
                    if(s_top->prec() >= op->prec()) {
                        _postfix.push(temp.pop());
                        if(temp.size() > 0) {
                            s = *temp.top();
                            s_top = static_cast<Operator*>(s);
                        }
                    }
                    else {
                        break;
                    }
                }
                temp.push(p);
            }
            break;
        }
        case FUNCTION: {
            Function* trig = static_cast<Function*>(p);
            if(temp.empty()) {
                temp.push(p);
            }
            else {
                try {
                    Token* f = *temp.top();
                    Operator* f_top = static_cast<Operator*>(f);
                    while(temp.size() > 0) {
                        if(f_top->prec() >= trig->prec()) {
                            _postfix.push(temp.pop());
                            if(temp.size() > 0) {
                                f = *temp.top();
                                f_top = static_cast<Operator*>(f);
                            }
                        }
                        else {
                            break;
                        }
                    }
                    temp.push(p);
                }
                catch(string op) {
                    cout << "Invalid Precedence (Shunting Yard Class), throwing " << op << endl;;
                    throw op;
                }
            }
            break;
        }
        default:
            throw p;
        }
    }
    while(temp.size() > 0) {
        _postfix.push(temp.pop());
    }
    return _postfix;
}

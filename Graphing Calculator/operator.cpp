#include "operator.h"

Operator::Operator(string op) : Token(op), _op(op), _precedence(0) {

}

int Operator::prec() { /* @return the precedence of the operators (ex. + & - equals precedence of 1) */
    if(_op == "+" || _op == "-") {
        _precedence = 1;
        return _precedence;
    }
    else if(_op == "*" || _op == "/" || _op == "sqrt") {
        _precedence = 2;
        return _precedence;
    }
    else if(_op == "^") {
        _precedence = 3;
        return _precedence;
    }
    else if(_op == "(") {
        return _precedence;
    }
    else if(_op == "sin" || _op == "cos" || _op == "tan" || _op == "log" || _op == "ln" || _op == "max" || _op == "n") {
        _precedence = 4;
        return _precedence;
    }
    else {
        throw _op;
    }
}

string Operator::OP() {
    return _op;
}

int Operator::getType() {
    return OPERATOR;
}

void Operator::print() const {
    cout << _op << endl;
}

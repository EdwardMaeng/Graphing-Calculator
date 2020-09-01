#include "function.h"

Function::Function(string f) : Token(f), _f(f), _precedence(4) {

}

int Function::prec() {
    return _precedence;
}

string Function::Func() {
    return _f;
}

int Function::getType() {
    return FUNCTION;
}

void Function::print() const {
    cout << _f << endl;
}

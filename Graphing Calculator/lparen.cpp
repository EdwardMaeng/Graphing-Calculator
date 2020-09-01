#include "lparen.h"

Lparen::Lparen(string l) : Token(l), _l(l), _precendence(0) {

}

string Lparen::lpar() {
    return _l;
}

int Lparen::prec() {
    return _precendence;
}

int Lparen::getType() {
    return LPAREN;
}

void Lparen::print() const {
    cout << _l << endl;
}

#include "rparen.h"

Rparen::Rparen(string r) : Token(r), _r(r), _precendece(4) {

}

string Rparen::rpar() {
    return _r;
}

int Rparen::prec() {
    return _precendece;
}

int Rparen::getType() {
    return RPAREN;
}

void Rparen::print() const {
    cout << _r << endl;
}

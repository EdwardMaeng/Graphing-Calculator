#include "number.h"

Number::Number(string num) : Token(num), _num(atof(num.c_str())), _n(num) {

}

double Number::num() {
    return _num;
}

string Number::n() {
    return _n;
}

int Number::getType() {
    return NUMBER;
}

void Number::print() const {
    cout << _num << endl;
}

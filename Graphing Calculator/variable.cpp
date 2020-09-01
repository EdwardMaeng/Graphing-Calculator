#include "variable.h"

Variable::Variable(string v) : Token(v), _v(v) {

}

string Variable::var() {
    return _v;
}

int Variable::getType() {
    return VARIABLE;
}

void Variable::print() const {
    cout << _v << endl;
}

#include "token.h"

Token::Token() : _str("") {

}

Token::Token(string s) : _str(s) {

}

int Token::getType() {
    return TOKEN;
}

void Token::print() const {
    cout << _str << endl;
}

ostream& operator <<(ostream& outs, Token* print_me) {
    outs << print_me->_str;
    return outs;
}

ostream& operator <<(ostream& outs, Token print_me) {
    outs << print_me._str;
    return outs;
}

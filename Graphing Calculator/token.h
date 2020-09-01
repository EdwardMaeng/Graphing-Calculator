#ifndef TOKEN_H
#define TOKEN_H

#include "constants.h"
#include "stack_and_queue.h"

class Token {
public:
    Token();
    Token(string s);
    virtual int getType();
    virtual void print() const;
    friend ostream& operator <<(ostream& outs, Token* print_me);
    friend ostream& operator <<(ostream& outs, Token print_me);

private:
    string _str;
};

#endif // TOKEN_H

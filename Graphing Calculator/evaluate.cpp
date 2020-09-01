#include "evaluate.h"

Evaluate::Evaluate() : _infix(), _postfix(), _exp("") {

}

Evaluate::Evaluate(string exp) : _infix(), _postfix(), _exp(exp) {

}

/*
 * Eval:
 * Loops through _exp (expression) and figures out (also creates a new) which ones are operators, left paren,
 * right paren, variables, numbers, and functions. When it is numbers it creates another loop to check their digits and
 * same thing applies for functions. It also uses shunting yard and rpn to essentailly figure out the value of y.
 */

double Evaluate::eval(double value) {
    string num;
    string term;
    for(int i = 0; i < _exp.length(); i++) {
        string s(1, _exp[i]);  // converts char to string

        if(s == "+" || s == "-" || s == "*" || s == "/" || s == "^") {
            _infix.push(new Operator(s));
        }
        else if(s == "(") {
            _infix.push(new Lparen(s));
        }
        else if(s == ")") {
            _infix.push(new Rparen(s));
        }
        else if(s == "x") {
            _infix.push(new Variable(s));
        }
        else if(_exp[i] > 96 && _exp[i] < 123) {
            while(_exp[i] > 96 && _exp[i] < 123) {
                string s(1, _exp[i]);
                term += s;
                i++;
            }
            if(term == "pi" || term == "e") {
                _infix.push(new Number(term));
            }
            else if(term == "theta") {
                _infix.push(new Variable(s));
            }
            else {
                _infix.push(new Function(term));
            }
            i--;
            term = "";
        }
        else {
            if(_exp[i] > 47 && _exp[i] < 58) {  // ascii table -> '0' = 48 and '9' = 57, thus the numbers between 0 through 9
                while(_exp[i] > 47 && _exp[i] < 58) {
                    string s(1, _exp[i]);  // converts char to string
                    num += s;  // adds two string together (ex. "1" + "0" to "10")
                    i++;
                }
                i--;  // decrements i because it will skip one when the both the loops increments
                _infix.push(new Number(num));
                num = "";  // set string num to an empty string
            }
            else {
                _infix.push(new Number(s));
            }
        }
    }

    _exp = "";

    try {
        Shunting_Yard sh(_infix);
        _postfix = sh.postfix();
        RPN r(_postfix);
        return r.rpn(value);
    }
    catch(Token* p) {
        cout << "Invalid (Evaluate Class), throwing " << p << endl;
        throw p;
    }
}

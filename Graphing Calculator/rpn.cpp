#include "rpn.h"

RPN::RPN(Queue<Token*> input) : _q(input) {

}

/*
 * RPN:
 * Has an input queue which is poped to determine the type of the each element of the input.
 * A type number simply pushes the poped input to the output stack unless pi is declared. The
 * variable works alike the number type. A type operator pops two values of stack output and depending
 * on the operator it either adds, subtract, multiply, and etc. A type function works similarly like
 * the type operator. All the "total" after going through operator and function is pushed back into
 * the stack output.
 */

double RPN::rpn(double value) {
    Token* p;
    double total;
    Stack<double> output;

    try {
        while(_q.size() > 0) {
            p = _q.pop();
            int type = p->getType();

            switch(type) {
            case NUMBER: {
                if(static_cast<Number*>(p)->n() == "pi") {
                    output.push(4*atan(1));  // value of pi (3.14...)
                }
                else if(static_cast<Number*>(p)->n() == "e") {
                    output.push(exp(1.0));   // value of euler's number (2.17...)
                }
                else {
                    output.push(static_cast<Number*>(p)->num());
                }
                break;
            }
            case VARIABLE: {
                output.push(value);
                break;
            }
            case OPERATOR: {
                double second = output.pop();
                double first = output.pop();
                string op = static_cast<Operator*>(p)->OP();
                if(op == "+") {
                    total = first + second;
                    output.push(total);
                }
                else if(op == "-") {
                    total = first - second;
                    output.push(total);
                }
                else if(op == "*") {
                    total = first * second;
                    output.push(total);
                }
                else if(op == "/") {
                    total = first / second;
                    output.push(total);
                }
                else if(op == "^") {
                    total = pow(first, second);
                    output.push(total);
                }
                else {
                    throw op;
                }
                break;
            }
            case FUNCTION: {
                string func = static_cast<Function*>(p)->Func();
                if(func == "sin") {
                    total = sin(output.pop());
                    output.push(total);
                }
                else if(func == "cos") {
                    total = cos(output.pop());
                    output.push(total);
                }
                else if(func == "tan") {
                    total = tan(output.pop());
                    output.push(total);
                }
                else if(func == "csc") {
                    total = 1/sin(output.pop());
                    output.push(total);
                }
                else if(func == "sec") {
                    total = 1/cos(output.pop());
                    output.push(total);
                }
                else if(func == "cot") {
                    total = 1/tan(output.pop());
                    output.push(total);
                }
                else if(func == "log") {
                    total = log(output.pop());
                    output.push(total);
                }
                else if(func == "ln") {
                    total = (log(output.pop()) / log(exp(1)));
                    output.push(total);
                }
                else if(func == "sqrt") {
                    total = sqrt(output.pop());
                    output.push(total);
                }
                else if(func == "max") {
                    double second = output.pop();
                    double first = output.pop();
                    total = max(first, second);
                    output.push(total);
                }
                else if(func == "n") {
                    total = -1 * output.pop();
                    output.push(total);
                }
                else {
                    throw p;
                }
                break;
            }
            default:
                throw p;
            }
        }
        return output.pop();
    }
    catch(int s) {
        cout << "Stack is empty (RPN Class), throwing size " << s << endl;
        throw s;
    }
}

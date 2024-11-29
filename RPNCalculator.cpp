#include "RPNCalculator.h"
#include "MyStack.h"
#include <cctype>
#include <iostream>

using namespace std;

int evaluateRPN(const string& expression) {
    MyStack<int> stack;
    size_t i = 0;

    while (i < expression.size()) {
        if (isspace(expression[i])) {
            ++i;
            continue;
        }
        if (isdigit(expression[i]) || (expression[i] == '-' && isdigit(expression[i + 1]))) {
            int num = 0;
            bool isNegative = false;

            if (expression[i] == '-') {
                isNegative = true;
                ++i;
            }

            while (i < expression.size() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                ++i;
            }

            stack.push(isNegative ? -num : num);
        }
        else {
            if (stack.isEmpty()) {
                cerr << "Error: Insufficient operands." << endl;
                return 0;
            }
            int b = stack.top();
            stack.pop();

            if (stack.isEmpty()) {
                cerr << "Error: Insufficient operands." << endl;
                return 0;
            }
            int a = stack.top();
            stack.pop();

            if (expression[i] == '+') {
                stack.push(a + b);
            }
            else if (expression[i] == '-') {
                stack.push(a - b);
            }
            else if (expression[i] == '*') {
                stack.push(a * b);
            }
            else {
                cerr << "Error: Unknown operator '" << expression[i] << "'." << endl;
                return 0;
            }
            ++i;
        }
    }

    if (stack.isEmpty()) {
        cerr << "Error: No result on stack." << endl;
        return 0;
    }
    return stack.top();
}

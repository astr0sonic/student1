#include "calculator.h"
#include <string>
#include <stack>
#include <cctype>
#include <cmath>
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isUnary(char c, size_t pos, const std::string& expr) {
    if (c == '-' && (pos == 0 || isOperator(expr[pos - 1]) || expr[pos - 1] == '('))
        return true;
    return false;
}

int precedence(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

double applyOperation(double a, double b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return std::pow(a, b);
    default:
        return 0;
    }
}

double calculate(const std::string& expr) {
    std::stack<double> values;
    std::stack<char> operators;

    for (size_t i = 0; i < expr.length(); ++i) {
        if (expr[i] == ' ') {
            continue;
        }
        else if (std::isdigit(expr[i]) || isUnary(expr[i], i, expr)) {
            double num = std::stod(expr.substr(i));
            while (i < expr.length() && (std::isdigit(expr[i]) || expr[i] == '.')) {
                ++i;
            }
            --i;
            values.push(num);
        }
        else if (expr[i] == '(') {
            operators.push(expr[i]);
        }
        else if (expr[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.pop();
        }
        else if (isOperator(expr[i])) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expr[i])) {
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.push(expr[i]);
        }
    }

    while (!operators.empty()) {
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}


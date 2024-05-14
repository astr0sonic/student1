#include <string>

double calculate(const std::string& expr);
bool isOperator(char c);
int precedence(char op);
double applyOperation(double a, double b, char op);
bool isValidExpression(const std::string& expr);
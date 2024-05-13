#include "bracket.h"
#include <stack>
#include <string>
bool checkBrackets(const std::string& s) {
    std::stack<char> brackets;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{' || c == '<') {
            brackets.push(c);
        }
        else if (c == ')' || c == ']' || c == '}' || c == '>') {
            if (brackets.empty()) {
                return false;
            }
            char top = brackets.top();
            brackets.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{') ||
                (c == '>' && top != '<')) {
                return false; 
            }
        }
    }

    return brackets.empty();
}

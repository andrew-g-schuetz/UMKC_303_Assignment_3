#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

 bool isOperator(char c);
 int precedence(char c);
bool isParantheseBalanced(const std::string& expression);
std::string infixToPostfix(const std::string& infixExpression);

#endif
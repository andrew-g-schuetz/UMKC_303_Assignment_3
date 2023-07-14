#include "expression.h"
#include <stack>
#include <string>
#include<iostream>

/// @brief Checks to see if a character is an operator
/// @param c - character given
/// @return true or false if the character is a operator
bool isOperator(char c){
    if(c == '+') return true;
    if(c == '-') return true;
    if(c == '*') return true;
    if(c == '/') return true;
    if(c == '%') return true;
    return false;
}

/// @brief 
//Checks to the precence value of a given character
/// @param c - an operator
/// @return -1 or 2 will return if a valid operator,if not 0 will return
int precedence(char c){
    if(c == '+' || c =='-'){
        return 1;
    }else if(c == '*' || c == '/' || c == '%'){
        return 2;
    }
    return 0;
    

}

/// @brief Checks to see if the given expression has balanced paranthese
/// @param expression 
/// @return true or fasle value given the conditions
bool isParantheseBalanced(const std::string& expression){
    std::stack<char> s;
    for(char c : expression){
        if(c == '(' || c =='{' || c =='['){
            s.push(c);
        }else if(c == ')' || c =='}' || c ==']'){
            if(s.empty()){
                return false;
            }

            char top = s.top();
            s.pop();

            if((c == ')' && top != '(') || (c == '}' && top != '{') && (c == ']' && top != '[')){
                return false;
            }
        }
    }

    return s.empty();
}

/// @brief Changes the string infix expression to postfix
/// @param infixExpression - expression string
/// @return string expression
std::string infixToPostfix(const std::string& infixExpression) {
    std::stack<char> s;
    std::string postfix;
    std::unordered_map<char, int> precedenceMap;
    precedenceMap['+'] = 1;
    precedenceMap['-'] = 1;
    precedenceMap['*'] = 2;
    precedenceMap['/'] = 2;
    precedenceMap['%'] = 2;

    for (char c : infixExpression) {
        if (std::isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();  // Discard the '('
        } else if (isOperator(c)) {
            while (!s.empty() && s.top() != '(' && precedenceMap[s.top()] >= precedenceMap[c]) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        } else {
            
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}



int main() {
    std::string expression;
    std::cout << "Please enter an infix expression: ";
    std::getline(std::cin, expression);
    
    bool validExpression;
    if(isParantheseBalanced(expression)){
        validExpression = true;
        std::cout << "Postfix Expression: " << infixToPostfix(expression) << std::endl;
    }else{
        while(validExpression != true){
            std::cout << "Parentheses are unbalanced, please try again" << std::endl;
            std::string newExpression;
            std::cout << "Please enter an infix expression: ";
            std::getline(std::cin, newExpression);
            if(isParantheseBalanced(newExpression)){
                std::cout << "Postfix Expression: " << infixToPostfix(expression) << std::endl;
                validExpression = true;
            }
        }
    }

    
    

    return 0;
}
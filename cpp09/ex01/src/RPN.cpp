#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
    return (token.size() == 1 &&
            (token[0] == '+' || token[0] == '-' ||
             token[0] == '*' || token[0] == '/'));
}

bool RPN::isNumber(const std::string& token) const {
    if (token.empty())
        return false;
    for (size_t i = 0; i < token.size(); i++) {
        if (!std::isdigit(static_cast<unsigned char>(token[i])))
            return false;
    }
    return true;
}

double RPN::applyOperator(double a, double b, const std::string& op) const {
    if (op == "+")
        return a + b;
    if (op == "-")
        return a - b;
    if (op == "*")
        return a * b;
    if (op == "/") {
        if (b == 0)
            throw std::runtime_error("division by zero");
        return a / b;
    }
    throw std::runtime_error("unknown operator");
}

double RPN::evaluate(const std::string& expression) {
    while (!_stack.empty())
        _stack.pop();

    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (isNumber(token)) {
            if (token.size() > 1)
                throw std::runtime_error("number too large");
            double value = token[0] - '0';
            _stack.push(value);
        } else if (isOperator(token)) {
            if (_stack.size() < 2)
                throw std::runtime_error("not enough operands");
            double b = _stack.top(); _stack.pop();
            double a = _stack.top(); _stack.pop();
            double result = applyOperator(a, b, token);
            _stack.push(result);
        } else {
            throw std::runtime_error("invalid token");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("invalid expression");

    return _stack.top();
}
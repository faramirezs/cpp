#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &other): s(other.s){}

RPN& RPN::operator=(const RPN &other){
	if (this == &other)
    	return *this;
	s = other.s;
	return *this;
}

RPN::~RPN() {}

int RPN::evaluateRPN(const std::string& expr) {
    std::istringstream ss(expr);
    std::string token;

    while (ss >> token) { // >> skips whitespace automatically
        if (token.size() == 1 && std::string("+-*/").find(token[0]) != std::string::npos) {
            if (s.size() < 2)
                throw std::runtime_error("Error");
            int b = s.top();
			s.pop();
            int a = s.top();
			s.pop();
            if (token[0] == '+')
				s.push(a + b);
            else if (token[0] == '-')
				s.push(a - b);
            else if (token[0] == '*')
				s.push(a * b);
            else if (token[0] == '/') {
                if (b == 0)
					throw std::runtime_error("Error: division by zero");
                s.push(a / b);
            }
        } else {
            // Must be a single-digit number (< 10 per spec)
            if (token.size() != 1 || !std::isdigit(token[0]))
                throw std::runtime_error("Error");
            s.push(token[0] - '0');
        }
    }
    if (s.size() != 1)
        throw std::runtime_error("Error");
    return s.top();
}

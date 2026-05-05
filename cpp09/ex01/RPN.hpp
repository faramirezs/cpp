#ifndef RPN_HPP
# define RPN_HPP
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

class RPN
{
private:
	std::stack<int> s;
public:
	RPN();
	RPN(const RPN &other);
	RPN& operator=(const RPN &other);
	~RPN();

	int evaluateRPN(const std::string& expr);
};


#endif

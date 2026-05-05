#include "RPN.hpp"


int main(int ac, char** av){

	if (ac != 2){
		std::cerr << "Error: no input" << std::endl;
		return 1;
	}
	try
	{
		RPN p;
		int i = p.evaluateRPN(av[1]);
		std::cout << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

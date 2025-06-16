# include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "The memory address of the str:" << &str << "\n";
    std::cout << "The memory address of stringPTR:" << stringPTR << "\n";
    std::cout << "The memory address of stringREF:" << &stringREF << "\n";

    std::cout << "Content of str:" << str << "\n";
    std::cout << "Content pointed to by stringPTR:" << *stringPTR << "\n";
    std::cout << "Content pointed to by stringREF:" << stringREF << "\n";
}
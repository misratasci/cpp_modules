
#include <string>
#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR;
	stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address of the string:\t\t" << &str << std::endl;
	std::cout << "Memory address held by stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:\t" << &stringREF << std::endl;

	std::cout << "Value of the string:\t\t\t" << str << std::endl;
	std::cout << "Value pointed to by stringPTR:\t\t" << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:\t\t" << stringREF << std::endl;

}
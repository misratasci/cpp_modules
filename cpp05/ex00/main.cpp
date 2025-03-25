
#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat low("loww", 151);
	}
	catch (const std::exception &e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		Bureaucrat high("hehe", -1);
	}
	catch (const std::exception &e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat inc("iii", 2);
		std::cout << inc;
		inc.incrementGrade();
		std::cout << inc;
		inc.incrementGrade();
	}
	catch (const std::exception &e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		Bureaucrat dec("ddd", 149);
		std::cout << dec;
		dec.decrementGrade();
		std::cout << dec;
		dec.decrementGrade();
	}
	catch (const std::exception &e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
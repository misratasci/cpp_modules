
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
		std::cout << inc << std::endl;
		inc.incrementGrade();
		std::cout << inc <<std::endl;
		inc.incrementGrade();
	}
	catch (const std::exception &e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		Bureaucrat dec("ddd", 149);
		std::cout << dec << std::endl;
		dec.decrementGrade();
		std::cout << dec << std::endl;
		dec.decrementGrade();
	}
	catch (const std::exception &e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Bureaucrat ali("Ali", 1);
  Bureaucrat misra("Misra", 50);
  Bureaucrat tanhan("Tanhan", 150);

  std::cout << ali << std::endl;
  std::cout << misra << std::endl;
  std::cout << tanhan << std::endl;

  ShrubberyCreationForm shrubbery("maslak");
  RobotomyRequestForm robotomy("elifnaz");
  PresidentialPardonForm pardon("Mehmet");

  std::cout << shrubbery << std::endl;
  std::cout << robotomy << std::endl;
  std::cout << pardon << std::endl;

  try {
    ali.signForm(shrubbery);
    misra.signForm(robotomy);
    ali.signForm(pardon);

    ali.executeForm(shrubbery);
    ali.executeForm(robotomy);
    ali.executeForm(pardon);

    tanhan.signForm(pardon);
    tanhan.executeForm(shrubbery);

    ShrubberyCreationForm unsigned_form("unsigned");
    ali.executeForm(unsigned_form);

  } catch (std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }
  return 0;
}

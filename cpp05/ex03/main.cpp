#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    Intern intern;
    AForm *form1 = NULL;
    AForm *form2 = NULL;
    AForm *form3 = NULL;

    form1 = intern.makeForm("shrubbery creation", "sss");
    form2 = intern.makeForm("robotomy request", "rrr");
    form3 = intern.makeForm("presidential pardon", "ppp");

    if (form1) {
      std::cout << *form1 << std::endl;
      delete form1;
    }
    if (form2) {
      std::cout << *form2 << std::endl;
      delete form2;
    }
    if (form3) {
      std::cout << *form3 << std::endl;
      delete form3;
    }

    try {
      AForm *invalidForm = intern.makeForm("random form", "target");
      delete invalidForm;
    } catch (std::exception &e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
    }

    Bureaucrat ali("Ali", 1);
    AForm *workForm = intern.makeForm("robotomy request", "Ayse");

    if (workForm) {
      ali.signForm(*workForm);
      ali.executeForm(*workForm);
      delete workForm;
    }

  } catch (std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}

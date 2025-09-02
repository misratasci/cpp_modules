#include "Intern.hpp"

Intern::Intern() {
  std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &src) {
  std::cout << "Intern copy constructor called" << std::endl;
  (void)src;
}

Intern::~Intern() { std::cout << "Intern destructor called" << std::endl; }

Intern &Intern::operator=(const Intern &src) {
  std::cout << "Intern assignment operator called" << std::endl;
  (void)src;
  return *this;
}

AForm *Intern::makeShrubberyCreationForm(const std::string target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string formName, const std::string target) {
  std::string formNames[3] = {"shrubbery creation", "robotomy request",
                              "presidential pardon"};

  AForm *(Intern::*formCreators[3])(const std::string) = {
      &Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm,
      &Intern::makePresidentialPardonForm};

  for (int i = 0; i < 3; i++) {
    if (formName == formNames[i]) {
      std::cout << "Intern creates " << formName << std::endl;
      return (this->*formCreators[i])(target);
    }
  }

  std::cout << "Intern cannot create " << formName
            << " form because it doesn't exist" << std::endl;
  throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
  return "Form not found!";
}

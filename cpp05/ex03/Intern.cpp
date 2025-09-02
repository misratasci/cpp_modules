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

FormType getFormType(const std::string &formName) {
    if (formName == "shrubbery creation")
        return SHRUBBERY_CREATION;
    if (formName == "robotomy request")
        return ROBOTOMY_REQUEST;
    if (formName == "presidential pardon")
        return PRESIDENTIAL_PARDON;
    return INVALID_FORM;
}

AForm *Intern::makeForm(const std::string formName, const std::string target) {
    std::cout << "Intern creates " << formName << std::endl;
    
    switch (getFormType(formName)) {
        case SHRUBBERY_CREATION:
            return new ShrubberyCreationForm(target);
        case ROBOTOMY_REQUEST:
            return new RobotomyRequestForm(target);
        case PRESIDENTIAL_PARDON:
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Intern cannot create " << formName
                      << " form because it doesn't exist" << std::endl;
            throw FormNotFoundException();
    }
}

const char *Intern::FormNotFoundException::what() const throw() {
  return "Form not found!";
}

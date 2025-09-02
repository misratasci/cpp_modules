#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

class Intern {
public:
  Intern();
  Intern(const Intern &src);
  ~Intern();
  Intern &operator=(const Intern &src);
  AForm *makeForm(const std::string formName, const std::string target);
  class FormNotFoundException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

private:
  AForm *makeShrubberyCreationForm(const std::string target);
  AForm *makeRobotomyRequestForm(const std::string target);
  AForm *makePresidentialPardonForm(const std::string target);
};
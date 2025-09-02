#pragma once

#include "AForm.hpp"
#include <exception>
#include <iostream>

class AForm;

class Bureaucrat {
private:
  const std::string name;
  int grade;

public:
  Bureaucrat();
  Bureaucrat(const Bureaucrat &src);
  Bureaucrat(const std::string name, int grade);
  ~Bureaucrat();
  Bureaucrat &operator=(const Bureaucrat &src);
  const std::string getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();
  void signForm(AForm &f);
  void executeForm(AForm const &form);
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &src);

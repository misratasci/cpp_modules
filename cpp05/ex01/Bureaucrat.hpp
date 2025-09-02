#pragma once

#include "Form.hpp"
#include <exception>
#include <iostream>

class Form;

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
  void signForm(Form &f);
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
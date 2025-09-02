#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {
private:
  const std::string name;
  bool is_signed;
  const int sign_grade;
  const int exec_grade;

public:
  AForm();
  AForm(const AForm &src);
  AForm(const std::string name, const int sign_grade, const int exec_grade);
  virtual ~AForm();
  AForm &operator=(const AForm &src);
  const std::string getName() const;
  void beSigned(const Bureaucrat &b);
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;
  virtual void execute(Bureaucrat const &executor) const = 0;
  void checkExecuteRequirements(Bureaucrat const &executor) const;
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, AForm const &src);

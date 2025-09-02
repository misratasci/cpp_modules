#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
  std::string target;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &src);
  ShrubberyCreationForm(const std::string target);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
  void execute(Bureaucrat const &executor) const;
  std::string getTarget() const;
};

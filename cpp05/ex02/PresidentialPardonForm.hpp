#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
  std::string target;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &src);
  PresidentialPardonForm(const std::string target);
  ~PresidentialPardonForm();
  PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
  void execute(Bureaucrat const &executor) const;
  std::string getTarget() const;
};

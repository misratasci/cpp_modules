#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
private:
  std::string target;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &src);
  RobotomyRequestForm(const std::string target);
  ~RobotomyRequestForm();
  RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
  void execute(Bureaucrat const &executor) const;
  std::string getTarget() const;
};

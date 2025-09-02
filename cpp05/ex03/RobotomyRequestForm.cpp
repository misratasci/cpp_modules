#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("default") {
  std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src), target(src.target) {
  std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {
  std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
  std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
  if (this != &src) {
    AForm::operator=(src);
    this->target = src.target;
  }
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  this->checkExecuteRequirements(executor);

  std::cout << "Drilling noises brrzzzz" << std::endl;

  static bool seeded = false;
  if (!seeded) {
    srand(time(NULL));
    seeded = true;
  }

  if (rand() % 2) {
    std::cout << this->target << " has been robotomized" << std::endl;
  } else {
    std::cout << "Robotomy failed on " << this->target << std::endl;
  }
}

std::string RobotomyRequestForm::getTarget() const { return this->target; }

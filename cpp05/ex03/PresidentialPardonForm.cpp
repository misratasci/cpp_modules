#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target("default") {
  std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &src)
    : AForm(src), target(src.target) {
  std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {
  std::cout << "PresidentialPardonForm parametric constructor called"
            << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
  std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
  if (this != &src) {
    AForm::operator=(src);
    this->target = src.target;
  }
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  this->checkExecuteRequirements(executor);

  std::cout << this->target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}

std::string PresidentialPardonForm::getTarget() const { return this->target; }

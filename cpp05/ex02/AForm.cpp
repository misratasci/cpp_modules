#include "AForm.hpp"

AForm::AForm()
    : name("default"), is_signed(false), sign_grade(150), exec_grade(150) {
  std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &src)
    : name(src.name), is_signed(src.is_signed), sign_grade(src.sign_grade),
      exec_grade(src.exec_grade) {
  std::cout << "AForm copy constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade)
    : name(name), is_signed(false), sign_grade(sign_grade),
      exec_grade(exec_grade) {
  std::cout << "AForm parametric constructor called" << std::endl;
  if (sign_grade < 1 || exec_grade < 1)
    throw GradeTooHighException();
  if (sign_grade > 150 || exec_grade > 150)
    throw GradeTooLowException();
}

AForm::~AForm() { std::cout << "AForm destructor called" << std::endl; }

AForm &AForm::operator=(const AForm &src) {
  std::cout << "AForm assignment operator called" << std::endl;
  if (this != &src)
    this->is_signed = src.is_signed;
  return *this;
}

const std::string AForm::getName() const { return this->name; }

void AForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > this->sign_grade)
    throw GradeTooLowException();
  this->is_signed = true;
}

bool AForm::getIsSigned() const { return this->is_signed; }

int AForm::getSignGrade() const { return this->sign_grade; }

int AForm::getExecGrade() const { return this->exec_grade; }

void AForm::checkExecuteRequirements(Bureaucrat const &executor) const {
  if (!this->is_signed)
    throw FormNotSignedException();
  if (executor.getGrade() > this->exec_grade)
    throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, AForm const &src) {
  os << "Form " << src.getName()
     << ", signed: " << (src.getIsSigned() ? "yes" : "no")
     << ", sign grade: " << src.getSignGrade()
     << ", exec grade: " << src.getExecGrade();
  return os;
}

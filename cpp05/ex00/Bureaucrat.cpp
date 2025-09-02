
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
  std::cout << "Default constructor for Bureaucrat " << this->getName()
            << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
    : name(src.getName()), grade(src.getGrade()) {
  std::cout << "Copy constructor for Bureaucrat" << this->getName()
            << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : name(name), grade(grade) {
  if (grade > 150)
    throw GradeTooLowException();
  else if (grade < 1)
    throw GradeTooHighException();
  else
    std::cout << "Name & grade constructor for Bureaucrat " << this->getName()
              << std::endl;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Destructor for Bureaucrat " << this->getName() << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
  std::cout << "Copy assignment operator for Bureaucrat" << this->getName()
            << std::endl;
  if (this == &src)
    return *this;
  this->grade = src.getGrade();
  return *this;
}

const std::string Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::incrementGrade() {
  if (this->getGrade() <= 1)
    throw GradeTooHighException();
  else
    this->grade--;
}

void Bureaucrat::decrementGrade() {
  if (this->getGrade() >= 150)
    throw GradeTooLowException();
  else
    this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade cannot be higher than 1!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade cannot be lower than 150!";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &src) {
  os << src.getName() << ", bureaucrat grade " << src.getGrade();
  return (os);
}
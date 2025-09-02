#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
  std::cout << "Default constructor for Bureaucrat " << this->getName()
            << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
    : name(src.name), grade(src.grade) {
  std::cout << "Copy constructor for Bureaucrat " << this->getName()
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
  std::cout << "Assignment operator for Bureaucrat " << this->getName()
            << " called" << std::endl;
  if (this != &src)
    this->grade = src.grade;
  return *this;
}

const std::string Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::incrementGrade() {
  if (this->grade <= 1)
    throw GradeTooHighException();
  this->grade--;
}

void Bureaucrat::decrementGrade() {
  if (this->grade >= 150)
    throw GradeTooLowException();
  this->grade++;
}

void Bureaucrat::signForm(AForm &f) {
  try {
    f.beSigned(*this);
    std::cout << this->name << " signed " << f.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->name << " couldn't sign " << f.getName() << " because "
              << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) {
  try {
    form.execute(*this);
    std::cout << this->name << " executed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->name << " couldn't execute " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &src) {
  os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
  return os;
}


#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): name("default"), grade(150) {

}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.getName()), grade(src.getGrade()) {

}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
    if (this == &src)
        return *this;
    this->grade = src.getGrade();
    return *this;
}

const std::string Bureaucrat::getName() const {
    return this->name;
}

const int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::incrementGrade() {
    if (this->getGrade() <= 1)
        throw GradeTooLowException();
    else
        this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->getGrade() >= 150)
        throw GradeTooHighException();
    else
        this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade cannot be higher than 150!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade cannot be lower than 1!";
}


std::ostream &operator<<(std::ostream &os, Bureaucrat const &src) {
    os << "Name: " << src.getName() << ", Grade: " << src.getGrade() << std::endl;
    return (os);
}
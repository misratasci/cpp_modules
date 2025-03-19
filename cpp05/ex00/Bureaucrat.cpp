
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): name("default"), grade(150) {

}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {

}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {

}

const std::string Bureaucrat::getName() const {

}

const int Bureaucrat::getGrade() const {

}

void Bureaucrat::incrementGrade() {

}

void Bureaucrat::decrementGrade() {

}

const char* Bureaucrat::GradeTooHighException::what() const throw() {

}

const char* Bureaucrat::GradeTooLowException::what() const throw() {

}


std::ostream &operator<<(std::ostream &os, Bureaucrat const &src) {

}
#include "Form.hpp"

Form::Form(): name("default"), is_signed(false), sign_grade(150), exec_grade(150) {
    std::cout << "Default constructor for Form " << this->getName() << std::endl;
}

Form::Form(const Form &src): name(src.getName()), is_signed(src.getIsSigned()),
								sign_grade(src.getSignGrade()), exec_grade(src.getExecGrade()) {
    std::cout << "Copy constructor for Form" << this->getName() << std::endl;
}

Form::Form(const std::string name, const int sign_grade, const int exec_grade):
	name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade) {
        std::cout << "Name & grades constructor for Form " << this->getName() << std::endl;
}

Form::~Form() {
    std::cout << "Destructor for Form " << this->getName() << std::endl;
}

Form &Form::operator=(const Form &src) {
    std::cout << "Copy assignment operator for Form" << this->getName() << std::endl;
    if (this == &src)
        return *this;
    this->is_signed = src.getIsSigned();
    return *this;
}

const std::string Form::getName() const {
    return this->name;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade cannot be higher than 1!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade cannot be lower than 150!";
}


std::ostream &operator<<(std::ostream &os, Form const &src) {
    os << src.getName() << ", Form grade " ;
    return (os);
}
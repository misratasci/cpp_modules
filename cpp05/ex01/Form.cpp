
# include "Form.hpp"

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

bool Form::getIsSigned() const {
    return this->is_signed;
}

int Form::getSignGrade() const {
    return this->sign_grade;
}

int Form::getExecGrade() const {
    return this->exec_grade;
}

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->sign_grade)
        throw GradeTooLowException();
    else
        this->is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "the grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "the grade is too low!";
}


std::ostream &operator<<(std::ostream &os, Form const &src) {
    os << src.getName() << ", with sign grade " << src.getSignGrade() << " and exec grade " << 
        src.getExecGrade() << " is ";
    if (!src.getIsSigned())
        os << "not ";
    os << "signed";
    return (os);
}
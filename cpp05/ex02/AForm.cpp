
# include "AForm.hpp"

AForm::AForm(): name("default"), is_signed(false), sign_grade(150), exec_grade(150) {
    std::cout << "Default constructor for AForm " << this->getName() << std::endl;
}

AForm::AForm(const AForm &src): name(src.getName()), is_signed(src.getIsSigned()),
								sign_grade(src.getSignGrade()), exec_grade(src.getExecGrade()) {
    std::cout << "Copy constructor for AForm" << this->getName() << std::endl;
}

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade):
	name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade) {
        std::cout << "Name & grades constructor for AForm " << this->getName() << std::endl;
}

AForm::~AForm() {
    std::cout << "Destructor for AForm " << this->getName() << std::endl;
}

AForm &AForm::operator=(const AForm &src) {
    std::cout << "Copy assignment operator for AForm" << this->getName() << std::endl;
    if (this == &src)
        return *this;
    this->is_signed = src.getIsSigned();
    return *this;
}

const std::string AForm::getName() const {
    return this->name;
}

bool AForm::getIsSigned() const {
    return this->is_signed;
}

int AForm::getSignGrade() const {
    return this->sign_grade;
}

int AForm::getExecGrade() const {
    return this->exec_grade;
}

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->sign_grade)
        throw GradeTooLowException();
    else
        this->is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "the grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "the grade is too low!";
}


std::ostream &operator<<(std::ostream &os, AForm const &src) {
    os << src.getName() << ", with sign grade " << src.getSignGrade() << " and exec grade " << 
        src.getExecGrade() << " is ";
    if (!src.getIsSigned())
        os << "not ";
    os << "signed";
    return (os);
}
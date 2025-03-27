
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
    AForm("ShrubberyCreationForm", 145, 137) {
    std::cout << "Default constructor for ShrubberyCreationForm " << this->getName() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &src): AForm(src) {
        std::cout << "Copy constructor for ShrubberyCreationForm " << this->getName() << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(
    const std::string name):
    AForm(name, 145, 137) {
        std::cout << "Name constructor for ShrubberyCreationForm " << this->getName() << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Destructor for ShrubberyCreationForm " << this->getName() << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &src) {
    std::cout << "Copy assignment operator for ShrubberyCreationForm" << this->getName() << std::endl;
    if (this == &src)
        return *this;
    this->setIsSigned(src.getIsSigned());
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    
}
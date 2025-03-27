
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm() {
    std::cout << "Default constructor for ShrubberyCreationForm " << this->getName() << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &src): AForm(src) {
        std::cout << "Copy constructor for ShrubberyCreationForm " << this->getName() << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(
    const std::string name, const int sign_grade, const int exec_grade):
    AForm(name, sign_grade, exec_grade) {
        std::cout << "Name & grades constructor for ShrubberyCreationForm " << this->getName() << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Destructor for AForm " << this->getName() << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &src) {

}
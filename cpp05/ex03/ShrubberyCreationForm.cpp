#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("default") {
  std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src), target(src.target) {
  std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {
  std::cout << "ShrubberyCreationForm parametric constructor called"
            << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
  std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
  if (this != &src) {
    AForm::operator=(src);
    this->target = src.target;
  }
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  this->checkExecuteRequirements(executor);

  std::string filename = this->target + "_shrubbery";
  std::ofstream file(filename.c_str());

  if (!file.is_open()) {
    std::cout << "Error: Could not create file " << filename << std::endl;
    return;
  }
  file << "                                    @" << std::endl;
  file << "                              @ @ @  @ @ @" << std::endl;
  file << "                            @  @\\/ @ @ /__@" << std::endl;
  file << "                            @@@ @\\ / @/  @ @" << std::endl;
  file << "                           @\\  \\/@| @ | @" << std::endl;
  file << "                          @__\\@ \\ |/ \\| / @" << std::endl;
  file << "                             __\\|@|  ||/__/@" << std::endl;
  file << "                            /  \\ \\  / /__" << std::endl;
  file << "                           @    \\  \\/ /   @" << std::endl;
  file << "                                 |\" '|" << std::endl;
  file << "                                 |\"  |" << std::endl;
  file << "                                 |\"  |" << std::endl;
  file << "                                ~|\"  |~" << std::endl;
  file << "                            ~~~~       ~~~" << std::endl;
  file << "                          ~~               ~~~" << std::endl;

  file.close();
  std::cout << "Shrubbery has been created in " << filename << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const { return this->target; }

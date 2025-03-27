
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm(const std::string name);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
        void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &src);

#endif
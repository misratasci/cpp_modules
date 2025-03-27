
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: AForm {
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm(const std::string name, const int sign_grade, const int exec_grade);
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
};

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &src);

#endif

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: AForm {
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm(const std::string name, const int sign_grade, const int exec_grade);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
};

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &src);

#endif
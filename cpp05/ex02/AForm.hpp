
#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool is_signed;
		const int sign_grade;
		const int exec_grade;
    public:
        AForm();
        AForm(const AForm &src);
		AForm(const std::string name, const int sign_grade, const int exec_grade);
        ~AForm();
        AForm &operator=(const AForm &src);
        const std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        virtual void beSigned(const Bureaucrat &b) = 0;
        virtual void execute(Bureaucrat const &executor) const = 0;
        class GradeTooHighException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, AForm const &src);

#endif
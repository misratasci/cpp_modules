
#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool is_signed;
		const int sign_grade;
		const int exec_grade;

    public:
        Form();
        Form(const Form &src);
		Form(const std::string name, const int sign_grade, const int exec_grade);
        ~Form();
        Form &operator=(const Form &src);
        const std::string getName() const;
        void beSigned(const Bureaucrat &b);
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        class GradeTooHighException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, Form const &src);

#endif
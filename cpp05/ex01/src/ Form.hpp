#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string  _name;
        bool               _isSigned;
        const int          _gradeToSign;
        const int          _gradeToExecute;

    public:
        Form(void);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form(void);

        Form(const std::string& name, int gradeToSign, int gradeToExecute);

        const std::string&  getName(void) const;
        bool                getIsSigned(void) const;
        int                 getGradeToSign(void) const;
        int                 getGradeToExecute(void) const;

        void  beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char * what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char * what(void) const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
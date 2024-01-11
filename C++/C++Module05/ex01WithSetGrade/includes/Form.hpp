#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;
        Form();
        
    public:
        Form(const std::string& name, int gradeToSign, int gradeToExecute); // in the constructor the boolean need to be false
        Form(const Form &other);
        Form &operator = (const Form &other);
        ~Form(void);

        std::string getName(void) const;
        bool getSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;

        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception{
        public:
            virtual const char *what() const throw() { 
                return "Form exception: Grade is too high!";}
        };

        class GradeTooLowException : public std::exception{
        public:
            virtual const char *what() const throw() { 
                return "Form exception: Grade is too low!";}
        };
};

std::ostream &operator<<(std::ostream &stream, const Form &form);

#endif // FORM_HPP
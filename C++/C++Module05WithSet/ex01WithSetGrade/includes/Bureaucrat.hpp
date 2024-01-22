#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150
# define LOGS_ENABLED 0

#include "Form.hpp"

class Form; // Forward declaration to avoid circular dependency
/* The purpose of the forward declaration is to break any potential 
 * circular dependencies between the Bureaucrat and Form classes. 
 * Circular dependencies occur when two or more classes depend on each other, 
 * leading to a situation where one class cannot be fully defined without the other. 
 * By using a forward declaration, you provide just enough information for the 
 * compiler to understand that the Form class exists, allowing you to use 
 * pointers or references to it in the Bureaucrat class without needing the full definition.
*/
class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator = (const Bureaucrat &other);
        ~Bureaucrat(void);

        const std::string& getName(void) const;
    
        int getGrade(void) const;
        void setGrade(int grade);

        void incrementGrade(void);
        void decrementGrade(void);

        void signForm(Form &form);
        
        class GradeTooHighException : public std::exception{
            public:
                virtual const char *what() const throw() { 
                    return "Bureaucrat exception: Grade is too high!"; } 
        };

        class GradeTooLowException : public std::exception{
            public:
                virtual const char *what() const throw() { 
                    return "Bureaucrat exception: Grade is too low!"; }
        };

    private:
        const std::string _name;
        int _grade;
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bureaucrat);

#endif // BUREAUCRAT_HPP
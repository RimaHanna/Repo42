#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

/*
 * Exceptions are thrown to the caller, a thrown exception will 
 * buble up to the caller, the caller of the caller until the route 
 * level (main), if main does not catch the exception, it will buble up
 * to the terminal, and force the program to exit. So main must catch the 
 * exception (try ... catch). If an intermediate caller catches the exception 
 * it will not buble up to main, and main will no be aware of the exception. 
*/

class Bureaucrat
{
    private:
        std::string _name;
        unsigned int _grade;

    public:
        Bureaucrat(void);
        Bureaucrat(const std::string name, int grade); // add try catch
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator = (const Bureaucrat &other);

        // Instead of using get and set and using this way for
        // getting the name, serves two purposes:
        // Non-modifiability of the returned string
        // Function const-qualification
        const std::string& getName(void) const;
        // void setName(const std::string name);

        int getGrade(void) const;
        void setGrade(int grade); // to do: verify here that the grade isn't out of range

        // Implementation of exception classes
        class GradeTooHighException : public std::exception{
        public:
            const char *what() const throw(); 
        };
        class GradeTooLowException : public std::exception{
        public:
            const char *what() const throw();
        };

        void incrementGrade(void);
        void decrementGrade(void);

        ~Bureaucrat(void);
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bureaucrat);

#endif // BUREAUCRAT_HPP
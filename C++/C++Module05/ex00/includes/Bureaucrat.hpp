#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150
# define LOGS_ENABLED 0
/*
 * Exceptions are thrown to the caller, a thrown exception will 
 * buble up to the caller, the caller of the caller until the route 
 * level (main), if main does not catch the exception, it will buble up
 * to the terminal, and force the program to exit. So main must catch the 
 * exception (try ... catch). If an intermediate caller catches the exception 
 * it will not buble up to main, and main will no be aware of the exception. 
*/
// I could have added a function to setGrade, and did the validation of the 
// grade in this function instead of doing it in the constructor and the
// incerment and decrement functions

class Bureaucrat
{
    public:
        class GradeTooHighException : public std::exception{
            public:
                const char *what() const throw(); 
        };
        class GradeTooLowException : public std::exception{
            public:
                const char *what() const throw();
        };

        Bureaucrat(const std::string& name, int grade); // add try catch
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator = (const Bureaucrat &other);
        ~Bureaucrat(void);

        std::string getName(void) const;
        
        int getGrade(void) const;

        void incrementGrade(void);
        void decrementGrade(void);

    private:
        const std::string _name;
        int _grade;
        Bureaucrat(void);
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bureaucrat);

#endif // BUREAUCRAT_HPP
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
	private:
		std::string 	_name;
		int				_grade;
	public:
		/* Constructors & Destructors */
		Bureaucrat(void);
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);

		/* Basic Operators */
		Bureaucrat const	&operator=(Bureaucrat const &copy);

		/* Getters & Setters */
		std::string const	&getName(void) const;
		int const			&getGrade(void) const;

		/* Main Member Functions */
		void	incrementGrade(void);
		void	decrementGrade(void);

		/* Exceptions */
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat);

#endif // BUREAUCRAT_HPP


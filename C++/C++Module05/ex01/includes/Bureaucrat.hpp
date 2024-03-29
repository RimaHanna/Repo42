#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP


#include <iostream>

class Form;

class Bureaucrat
{
	private:
		std::string 		_name;
		int					_grade;
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
		void	signForm(Form &form);

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
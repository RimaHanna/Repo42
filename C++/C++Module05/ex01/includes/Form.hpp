#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	public:
		/* Constructors & Destructors */
		Form(void);
		Form(std::string const &name, int const &gradeTosign, int const &gradeTo_gradeToExecute);
		Form(Form const &copy);
		~Form(void);

		/* Basic Operators */
		Form const	&operator=(Form const &copy);

		/* Getters & Setters */
		std::string const	&getName(void) const;
		bool const			&getIsSigned(void) const;
		int const			&getGradeToSign(void) const;
		int const			&getGradeToExecute(void) const;

		/* Main Member Functions */
		void	beSigned(Bureaucrat &bureaucrat);

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

std::ostream	&operator<<(std::ostream &str, Form const &form);

#endif // FORM_HPP
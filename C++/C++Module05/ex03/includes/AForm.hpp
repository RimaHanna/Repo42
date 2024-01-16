#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	public:
		/* Constructors & Destructors */
		AForm(void);
		AForm(std::string const &name, int const &gradeTosign, int const &gradeTo_gradeToExecute);
		AForm(std::string const &type, std::string const &target);
		AForm(AForm const &copy);
		virtual ~AForm(void);

		/* Basic Operators */
		AForm const	&operator=(AForm const &copy);

		/* Getters & Setters */
		std::string const	&getName(void) const;
		bool const			&getIsSigned(void) const;
		int const			&getGradeToSign(void) const;
		int const			&getGradeToExecute(void) const;

		/* Main Member Functions */
		void	beSigned(Bureaucrat &bureaucrat);
		void 	execute(Bureaucrat const & executor) const;
		virtual void	executed(Bureaucrat const &bureaucrat) const = 0;
        static AForm *makeForm(std::string const &type, std::string const &target);
		virtual std::string const	&getTarget(void) const = 0;


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
		class AFormNotSignedException: public std::exception
		{
			public:
				virtual char const *what(void) const throw();
		};

		class InvalidFormException: public std::exception
		{
			public:
				virtual char const *what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, AForm const &form);

#endif // FORM_HPP
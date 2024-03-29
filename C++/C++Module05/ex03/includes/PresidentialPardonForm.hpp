#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;
	public:
		/* Constructors & Destructors */
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		~PresidentialPardonForm(void);

		/* Basic Operators */
		PresidentialPardonForm const	&operator=(PresidentialPardonForm const &copy);

		/* Main Member Functions */
		void	executed(Bureaucrat const &bureaucrat) const;
		static AForm *makeForm(AForm *aform, std::string const &type, std::string const &target);
		std::string const	&getTarget(void) const;
};

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form);

#endif
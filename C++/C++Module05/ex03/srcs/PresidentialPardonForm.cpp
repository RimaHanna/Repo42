#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm::AForm("PresidentialPardonForm", 25, 5), _target("null")
{
    std::cout << "PresidentialPardonForm default constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm::AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): AForm::AForm(copy), _target(copy._target)
{
    std::cout << "PresidentialPardonForm copy constructor called!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm destructor called!" << std::endl;
}

PresidentialPardonForm const	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
    std::cout << "PresidentialPardonForm copy assignement operator called!" << std::endl;
	return (*this);
}

void	PresidentialPardonForm::executed(const Bureaucrat &bureaucrat) const
{
	(void)bureaucrat;
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

AForm *PresidentialPardonForm::makeForm(AForm *aform, std::string const &type, std::string const &target)
{
	if (aform == NULL && type == "presidential pardon")
		return (new PresidentialPardonForm(target));
	return (aform);
}

std::string const	&PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form)
{
	return (str << form.getName() << " form, signed: " << (form.getIsSigned() == true ? "yes" : "no") << ", sign grade: " << form.getGradeToSign() << ", exec grade: " << form.getGradeToExecute());
}
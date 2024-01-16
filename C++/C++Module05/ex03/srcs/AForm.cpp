#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm::AForm(void): _name("default"), _isSigned(false), _gradeToSign(30), _gradeToExecute(60)
{
    std::cout << "AForm default constructor called!" << std::endl; 
}

AForm::AForm(std::string const &name, int const &signGrade, int const &execGrade): _name(name), _isSigned(false), _gradeToSign(signGrade), _gradeToExecute(execGrade)
{
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw (AForm::GradeTooHighException());
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw (AForm::GradeTooLowException());
    std::cout << "AForm " << this->getName() << " constructor called!" << std::endl;
}

AForm::AForm(AForm const &copy): _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	*this = copy;
    std::cout << "AForm " << this->getName() << " copy constructor called!" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm " << this->getName() << " default destructor has been called" << std::endl;
}

AForm const	&AForm::operator=(const AForm &copy)
{
	this->_isSigned = copy._isSigned;
    std::cout << "AForm " << this->getName() << " copy assignement operator called!" << std::endl;
	return (*this);
}

std::string const	&AForm::getName(void) const
{
	return (this->_name);
}

int const	&AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int const	&AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

bool const	&AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw (AForm::GradeTooLowException());
	else
	{
		this->_isSigned = true;
		std::cout << bureaucrat.getName() << " successfully signed " << this->_name << std::endl;
	}
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->_isSigned == false)
		throw (AForm::AFormNotSignedException());
	else if (executor.getGrade() > this->_gradeToSign)
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout << executor.getName() << " executes form: " << this->_name << std::endl;
		this->executed(executor);
	}
}

AForm *AForm::makeForm(std::string const &type, std::string const &target)
{
	AForm *aform;
	aform = NULL;
	aform = ShrubberyCreationForm::makeForm(aform, type, target);
	aform = RobotomyRequestForm::makeForm(aform, type, target);
	aform = PresidentialPardonForm::makeForm(aform, type, target);
	return (aform);
}

char const	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm exception: Grade is too high");
}

char const	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm Exception: Grade is too low");
}

char const	*AForm::AFormNotSignedException::what(void) const throw()
{
	return ("AForm exeception: AForm not signed");
}

char const	*AForm::InvalidFormException::what(void) const throw()
{
	return ("AForm exeception: Invalid Form Exception");
}

std::ostream	&operator<<(std::ostream &str, AForm const &form)
{
	return (str << form.getName() << " form, signed: " << (form.getIsSigned() == true ? "yes" : "no") << ", sign grade: " << form.getGradeToSign() << ", exec grade: " << form.getGradeToExecute());
}
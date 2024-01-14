#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("default"), _isSigned(0), _gradeToSign(30), _gradeToExecute(60)
{
    std::cout << "Form default constructor called!" << std::endl; 
}

Form::Form(std::string const &name, int const &signGrade, int const &execGrade): _name(name), _isSigned(0), _gradeToSign(signGrade), _gradeToExecute(execGrade)
{
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw (Form::GradeTooHighException());
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw (Form::GradeTooLowException());
    std::cout << "Form " << this->getName() << " constructor called!" << std::endl;
}

Form::Form(Form const &copy): _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	*this = copy;
    std::cout << "Form " << this->getName() << " copy constructor called!" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form " << this->getName() << " default destructor has been called" << std::endl;

}

Form const	&Form::operator=(const Form &copy)
{
	this->_isSigned = copy._isSigned;
    std::cout << "Form " << this->getName() << " copy assignement operator called!" << std::endl;
	return (*this);
}

std::string const	&Form::getName(void) const
{
	return (this->_name);
}

int const	&Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int const	&Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

bool const	&Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw (Form::GradeTooLowException());
	else
	{
		this->_isSigned = 1;
		std::cout << bureaucrat.getName() << " successfully signed " << this->_name << std::endl;
	}
}

char const	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Form exception: Grade is too high");
}

char const	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Form Exception: Grade is too low");
}

std::ostream	&operator<<(std::ostream &str, Form const &form)
{
	return (str << form.getName() << " form, signed: " << (form.getIsSigned() == true ? "yes" : "no") << ", sign grade: " << form.getGradeToSign() << ", exec grade: " << form.getGradeToExecute());
}
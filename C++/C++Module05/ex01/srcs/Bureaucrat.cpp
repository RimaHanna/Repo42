#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	this->_grade = grade;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
    std::cout << "Bureaucrat "<< this->getName() << " constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	*this = copy;
    std::cout << "Bureaucrat " << this->getName() << " copy constructor called!" << std::endl;

}

Bureaucrat::~Bureaucrat(void)
{
    std::cout <<  "Bureaucrat " << this->getName() << " destructor called!" << std::endl;
}

Bureaucrat const	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->_name = copy._name;
	this->_grade = copy._grade;
    std::cout << "Bureaucrat " << this->getName() << " copy assignement operator called!" << std::endl;
	return (*this);
}

std::string const	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int const	&Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot sign " << form.getName() << " because: " << e.what() << std::endl;
	}
}

char const	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat exception: Grade is too high");
}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat exception: Grade is too low");
}

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void){
    if (LOGS_ENABLED)
        std::cout << "Default constructor called!" << std::endl; 
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade){
    this->setGrade(this->_grade);
    std::cout << "Constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other){
    *this = other;
    std::cout << "Bureaucrat " << this->getName() << " copy constructor called!" << std::endl;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &other){
    if (this != &other)
    {
    	const_cast<std::string&>(this->_name) = other._name;
        this->_grade = other._grade;
    }
    std::cout << "Bureaucrat " << this->getName() << " copy assignement operator called!" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat(void){
    std::cout <<  "Bureaucrat " << this->getName() << " default destructor called!" << std::endl;
}

const std::string& Bureaucrat::getName(void) const{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const{
    return (this->_grade);
}

void Bureaucrat::setGrade(int grade){
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    else if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
    else
        this->_grade = grade;
}

void Bureaucrat::incrementGrade(void){
    this->setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade(void){
    this->setGrade(this->_grade + 1);
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bureaucrat)
{
    stream << Bureaucrat.getName() << ", bureaucrat grade " 
        << Bureaucrat.getGrade();
    return (stream);
}
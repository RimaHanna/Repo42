#include "Bureaucrat.hpp"

#define LOGS_ENABLED 0

Bureaucrat::Bureaucrat(void){
    if (LOGS_ENABLED)
        std::cout << "Default constructor called!" << std::endl; 
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name){
    this->setGrade(grade);
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

const std::string& Bureaucrat::getName(void) const{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const{
    return (this->_grade);
}

void Bureaucrat::setGrade(int grade){
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Bureaucrat exception: Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Bureaucrat exception: Grade is too low!";
}

Bureaucrat::~Bureaucrat(void){
    std::cout <<  "Bureaucrat " << this->getName() << " default destructor called!" << std::endl;
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
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void){
    if (LOGS_ENABLED)
        std::cout << "Default Bureaucrat constructor called!" << std::endl; 
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade){
    if (grade < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (grade > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade){
    std::cout << "Bureaucrat " << this->getName() << " copy constructor called!" << std::endl;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &other){
    if (this != &other)
    {
        _grade = other.getGrade();
    }
    std::cout << "Bureaucrat " << this->getName() << " copy assignement operator called!" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat(void){
    std::cout <<  "Bureaucrat " << this->getName() << " default destructor called!" << std::endl;
}

std::string Bureaucrat::getName(void) const{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const{
    return (this->_grade);
}

void Bureaucrat::incrementGrade(void){
    if (this->_grade - 1 < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    this->_grade = this->_grade - 1;
}

void Bureaucrat::decrementGrade(void){
    if (this->_grade + 1 > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = this->_grade + 1;
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << "Bureaucrat " << this->_name << " signed " << form.getName() << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "Bureaucrat " << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bureaucrat)
{
    stream << Bureaucrat.getName() << ", bureaucrat grade " 
        << Bureaucrat.getGrade();
    return (stream);
}


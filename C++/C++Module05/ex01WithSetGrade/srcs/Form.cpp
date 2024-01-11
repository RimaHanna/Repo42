#include "Form.hpp"

Form::Form() : _name("unnamed"), _gradeToSign(5), _gradeToExecute(6){
    if (LOGS_ENABLED)
        std::cout << "Default Form constructor called!" << std::endl; 
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name) , _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    if (gradeToExecute < HIGHEST_GRADE || gradeToSign < HIGHEST_GRADE)
        throw Form::GradeTooHighException();
    else if (gradeToExecute > LOWEST_GRADE || gradeToSign > LOWEST_GRADE)
        throw Form::GradeTooLowException();
    this->_signed = false;
    std::cout << "Form " << this->getName() << " constructor called!" << std::endl;    
}

Form::Form(const Form &other) : _name(other._name),
         _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){
    std::cout << "Form " << this->getName() << " copy constructor called!" << std::endl;
}

Form &Form::operator = (const Form &other){
    if (this != &other)
    {
        // do not assign the other attributes because 
        // they are constant and can't be changed
        this->_signed = other._signed;
    }
    std::cout << "Form " << this->getName() << " copy assignement operator called!" << std::endl;
    return *this;    
}

Form::~Form(void) {
	std::cout << "Form " << this->getName() << " default destructor has been called" << std::endl;
}

std::string Form::getName(void) const{
    return (this->_name);
}

bool Form::getSigned(void) const{
    return this->_signed;

}
int Form::getGradeToSign(void) const{
    return this->_gradeToSign;
}

int Form::getGradeToExecute(void) const{
    return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() <= this->_gradeToSign)
        this->_signed = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &stream, const Form &form)
{
    stream << "Form name: " << form.getName() << std::endl;
    stream << "Grade to sign: " << form.getGradeToSign() << std::endl;
    stream << "Grade to execute: " << form.getGradeToExecute() << std::endl;
	stream << "Signed: " << (form.getSigned() == true ? "yes" : "no") << "\n";
    return (stream);
}

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm::AForm("ShrubberyCreationForm", 145, 137), _target("null")
{
    std::cout << "ShrubberyCreationForm default constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): AForm::AForm(copy), _target(copy._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm destructor called!" << std::endl;
}

ShrubberyCreationForm const	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
    std::cout << "ShrubberyCreationForm copy assignement operator called!" << std::endl;
	return (*this);
}

void	ShrubberyCreationForm::executed(const Bureaucrat &bureaucrat) const
{
	std::ofstream	outfile;
	
	outfile.open((this->_target + "_shrubbery").c_str());
	if (outfile.fail())
	{
		std::cout << "Could not open output file" << std::endl;
		return ;
	}
//	outfile << TREE;
    outfile << "      *\n";
    outfile << "     ***\n";
    outfile << "    *****\n";
    outfile << "   *******\n";
    outfile << "  *********\n";
    outfile << " ***********\n";
    outfile << "*************\n";
	outfile.close();
	std::cout << bureaucrat.getName() << " successfully created a shrubbery" << std::endl;
}

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &form)
{
	return (str << form.getName() << " form, signed: " << (form.getIsSigned() == true ? "yes" : "no") << ", sign grade: " << form.getGradeToSign() << ", exec grade: " << form.getGradeToExecute());
}
#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std:: cout << "I love having extra bacon for my";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. " << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I";
	std::cout << "wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here";
	std::cout << " since last month."<< std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! ";
	std::cout << "I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*ptr_complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*ptr_complain[i])();
			break;
		}
		i++;
	}
}

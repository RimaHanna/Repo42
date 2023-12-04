#include "Harl.hpp"

int	level_is(char *argv)
{
	int i = 0;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4)
	{
		if (levels[i] == argv)
			return i;
		i++;
	}
	return (-1);
}

void	harl_switch(char *argv, Harl & H)
{
	switch (level_is(argv))
	{
		case 0:
			H.complain("DEBUG");
			std::cout << std::endl;
			H.complain("INFO");
			std::cout << std::endl;
			H.complain("WARNING");
			std::cout << std::endl;
			H.complain("ERROR");
			break;
		case 1:
			H.complain("INFO");
			std::cout << std::endl;
			H.complain("WARNING");
			std::cout << std::endl;
			H.complain("ERROR");
			break;
		case 2:
			H.complain("WARNING");
			std::cout << std::endl;
			H.complain("ERROR");
			break;
		case 3:
			H.complain("ERROR");
			break;
		default:
			std::cout << "Probably complaining about insignificant problems" << std::endl;
			break;
	}
}


int main(int argc, char **argv)
{
	Harl H;
	if (argc != 2)
	{
		std::cout << "Harl i don't want to hear everything!!!" << std::endl;
		return (-1);
	}
	else
		harl_switch(argv[1], H);
	return (0);
}
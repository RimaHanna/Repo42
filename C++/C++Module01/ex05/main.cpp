#include "Harl.hpp"

int main()
{
	Harl H;
	std::string level;

	while(1)
	{
		std::cout << "Enter a valid level for Harl: "; 
		if (!std::getline(std::cin, level))
		{
			std::cout << std::endl;
			std::cout << "Ctrl+D detected. End of input." << std::endl;
			return (0);
		}
		if (!level.empty() && (level == "DEBUG" || level == "INFO" 
				|| level == "WARNING" || level == "ERROR"))
		{
			H.complain(level);
		}
	}
	return (0);
}
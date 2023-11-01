#include "Phonebook.hpp"

/**
 * Phonebook phb1: the constructor is directly called in this way
*/
int main(void)
{
	Phonebook phb;
	// instead of doing a construcor i can directly write the message here
	std::string userCommandInput;
	while (1)
	{	
		std::cout << "\x1B[1;38;5;4mEnter command ADD, SEARCH or EXIT.\x1B[0m" << std::endl;
		std::cout << "\x1B[38;5;4mYour command > \x1B[0m";
		std::getline(std::cin, userCommandInput);
		
		if (userCommandInput == "ADD")
			phb.add();
		else if (userCommandInput == "SEARCH")
			phb.search();
		else if (userCommandInput == "EXIT")
		{
			std::cout << "End of program..." << std::endl;
			std::exit(0);
		}
	}
	return (0);
}
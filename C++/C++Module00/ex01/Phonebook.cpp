#include "Phonebook.hpp"

/**
 * @def Initialization of the Constructor
 * @brief Create a constructor: "name of the class" followed by "::"
 * followed by "method name". (The method for the constructor should
 * have the same name as the class)
 * @brief The initial role of the constructor is to initialize the attribute
 * because we don't have the right to initialize it anywhere else.
 */
Phonebook::Phonebook()
{
	this->phb_index = 0;
	std::cout << "\x1B[1;38;5;5mWelcome to Booky! Manage up to 8 contacts." 
    	<< " Exceeding 8 contacts replaces the oldest." << std::endl;
}

/**
 *@brief Initialization of the Destructor, identified by the symbol "~" 
*/
Phonebook::~Phonebook()
{

}

/**
 * @brief Executing the method
 * @brief Declaring a string to be filled with the data.
*/
void	Phonebook::add(void)
{
	std::string userInputStr;

	userInputStr = "";
	if (this->phb_index > 7)
	{
		std::cout << "Warning: Overwritting over the oldest registered "
					<< "contact" << std::endl;
	}
	while (!std::cin.eof() && userInputStr.empty())
	{
		std::cout << "Enter a first name: "; 
		std::getline(std::cin, userInputStr);
		if (!userInputStr.empty())
			this->phb_contacts[this->phb_index % 8].set_firstName(userInputStr);
	}
	userInputStr.erase();
	while (!std::cin.eof() && userInputStr.empty())
	{
		std::cout << "Enter a last name: "; 
		
		if (std::getline(std::cin, userInputStr) && !userInputStr.empty())
			this->phb_contacts[this->phb_index % 8].set_lastName(userInputStr);
	}
	userInputStr.erase();
	while (!std::cin.eof() && userInputStr.empty())
	{
		std::cout << "Enter a nickname: "; 
		if (std::getline(std::cin, userInputStr) && !userInputStr.empty())
			this->phb_contacts[this->phb_index % 8].set_nickname(userInputStr);
	}
	userInputStr.erase();
	while (!std::cin.eof() && userInputStr.empty())
	{
		std::cout << "Enter a phone number: "; 
		if (std::getline(std::cin, userInputStr) && !userInputStr.empty())
			this->phb_contacts[this->phb_index % 8].set_phoneNumber(userInputStr);
	}
	userInputStr.erase();
	while (!std::cin.eof() && userInputStr.empty())
	{
		std::cout << "Enter a darkest secret: ";
		if (std::getline(std::cin, userInputStr) && !userInputStr.empty())
		{
			this->phb_contacts[this->phb_index % 8].set_darkestSecret(userInputStr);
			std::cout << "\x1B[1;38;5;2mSuccessfully contact # " << (phb_index % 8 + 1)
						<< " registered\x1B[0m" << std::endl;  
		}
	}
	userInputStr.erase();
	this->phb_index++;
}

void	Phonebook::print(Contacts Contacts)
{
	std::cout << std::endl << "\x1B[1;38;5;1mRequesting contact information...\x1B[0m" << std::endl;
	if (!Contacts.get_firstName().size())
	{
		std::cout << "Failed to get info for this contact" << std::endl;
		return ;
	}
	std::cout << "First Name: " << Contacts.get_firstName() << std::endl;
	std::cout << "Last Name: " << Contacts.get_lastName() << std::endl;
	std::cout << "Nickname: " << Contacts.get_nickname() << std::endl;
	std::cout << "Phone Number: " << Contacts.get_phoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << Contacts.get_darkestSecret() << std::endl;
}

void	Phonebook::search(void)
{
	std::string	str;

	if (!available_list(this->phb_contacts))
	{
		std::cout << std::endl << "Phonebook is empty!" << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		std::cout << "Select an index: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
					this->phb_contacts[str[0] - 1 - '0'].get_firstName().size())
				break ;
		}
		if (str != "")
			std::cout << "\x1B[1;38;5;1mInvalid index!\x1B[0m" << std::endl;
	}
	if (!std::cin.eof())
		this->print(this->phb_contacts[str[0] - 1 - '0']);
}
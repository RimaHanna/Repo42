#include "Contacts.hpp"

std::string	fill_spaces(int size)
{
	std::string spacesString;
	while (size--)
		spacesString.append(" ");
	return spacesString;
}

std::string	resize(std::string str, unsigned int size)
{
	if (str.size() > size)
	{
		str.resize(size);
		str[str.size() - 1] = '.';
	}
	return str;
}

int	available_list(Contacts phb_contacts[8])
{
	char		c;
	int			i;
	std::string str;

	i = 0;
	c = '0';
	
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	while (++c <= '8')
	{
		if (phb_contacts[c - 1 - '0'].get_firstName().size() && ++i)
		{
			str = c;
			str = resize(str, 10);
			std::cout << "|" << fill_spaces(10 - str.size()) << str;
			str = resize(phb_contacts[c - 1 - '0'].get_firstName(), 10);
			std::cout << "|" << fill_spaces(10 - str.size()) << str;
			str = resize(phb_contacts[c - 1 - '0'].get_lastName(), 10);
			std::cout << "|" << fill_spaces(10 - str.size()) << str;
			str = resize(phb_contacts[c - 1 - '0'].get_nickname(), 10);
			std::cout << "|" << fill_spaces(10 - str.size()) << str << "|";
			std::cout << std::endl;
		}
	}
	std::cout << " ------------------------------------------- " << std::endl;
	return (i);
}
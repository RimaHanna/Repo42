#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>
#include <string>

class Contacts
{
	public:
		Contacts();
		~Contacts();
		void	set_firstName(std::string str);
		void	set_lastName(std::string str);
		void	set_nickname(std::string str);
		void	set_phoneNumber(std::string str);
		void	set_darkestSecret(std::string str);
		std::string get_firstName(void) const;
		std::string get_lastName(void) const;
		std::string get_nickname(void) const;
		std::string get_phoneNumber(void) const;
		std::string get_darkestSecret(void) const;

	private:
		std::string c_firstName;
		std::string c_lastName;
		std::string c_nickname;
		std::string c_phoneNumber;
		std::string c_darkestSecret;
};

#endif
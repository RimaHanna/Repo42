#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include "Contacts.hpp"

/**
 * @brief class definition
 * 
*/
class Phonebook
{
	public:
		Phonebook();
		~Phonebook();
		void	add(void);
		void	search(void);
		void	print(Contacts Contacts);
	// All the attribute of the class should be private
	private:
		int	phb_index;
		Contacts phb_contacts[8];
};

/**
 * @name Print list with contacts
*/
int	available_list(Contacts phb_contacts[8]);

#endif
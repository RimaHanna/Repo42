#include "Contacts.hpp"

Contacts::Contacts()
{

}

Contacts::~Contacts()
{

}

void	Contacts::set_firstName(std::string str)
{
	this->c_firstName = str;
}

void	Contacts::set_lastName(std::string str)
{
	this->c_lastName = str;
}

void	Contacts::set_nickname(std::string str)
{
	this->c_nickname = str;
}

void	Contacts::set_phoneNumber(std::string str)
{
	this->c_phoneNumber = str;
}

void	Contacts::set_darkestSecret(std::string str)
{
	this->c_darkestSecret = str;
}

std::string Contacts::get_firstName(void) const
{
	return (this->c_firstName);
}

std::string Contacts::get_lastName(void) const
{
	return (this->c_lastName);
}

std::string Contacts::get_nickname(void) const
{
	return (this->c_nickname);
}

std::string Contacts::get_phoneNumber(void) const
{
	return (this->c_phoneNumber);
}

std::string Contacts::get_darkestSecret(void) const
{
	return (this->c_darkestSecret);
}
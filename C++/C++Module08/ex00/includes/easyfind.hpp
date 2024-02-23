#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>
# include <exception>
# include <algorithm> // std::find

class EasyFindException : public std::exception
{
	public:
		const char *what() const throw()
        {
			return "Exception: element not found within container";
   		}
};

template<typename T>
bool easyfind(T& container, int toFind)
{
	if (std::find(container.begin(), container.end(), toFind) == container.end())
		throw EasyFindException();
	else
        return true;
}

#endif // EASYFIND_HPP
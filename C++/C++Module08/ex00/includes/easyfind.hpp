#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>
# include <exception>
# include <algorithm>

class EasyFindException : public std::exception
{
	public:
		const char *what() const throw()
        {
			return "Exception: element not found within container";
   		}
};

template<typename T>
bool easyfind(T& container, int find)
{
	if (std::find(container.begin(), container.end(), find) == container.end())
		throw EasyFindException();
	else
        return true;
}

#endif // EASYFIND_HPP
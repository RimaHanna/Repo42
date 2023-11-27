#include <fstream>
#include <string>
#include <iostream>

/**
 * ofstream: open a file for writing 
 * The .c_str() member function is used in C++ to obtain a pointer to 
 * an array that contains a null-terminated sequence of 
 * characters (a C-style string) representing the contents of a 
 * std::string object. 
**/
int replace(char **argv, std::string str)
{
	std::ofstream ofs((std::string(argv[1]) + ".replace").c_str());
	if (ofs.fail())
	{
		std::cout << "Fail to open the ouput file" << std::endl;
		return (1); 
	}
	int i = 0;
	int pos = 0;
	while (i < (int)str.size())
	{
		pos = str.find(argv[2], i);
		if (pos == i)
		{
			ofs << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else
			ofs << str[i];
		i++;
	}
	ofs.close();
	return 0;
}


/**
 * ifstream: open a file for reading
 * ifs >> std::noskipws >> c: Reads a character (c) from the input 
 * file stream (ifs) with whitespace preservation (std::noskipws)
 *
*/
int main(int argc, char **argv)
{
	std::string	str;
	if (argc != 4 || !argv[2][0] || !argv[3][0])
	{
		std::cout << "Program arguments error" << std::endl;
		return (-1);
	}

	std::ifstream	ifs(argv[1]);
	if (!ifs.is_open())
	{
		std::cout << "Coulnd't open the input file" << std::endl;
		return (-1);
	}
	char	c;
	while (!ifs.eof() && ifs >> std::noskipws >> c)
		str = str + c;
	ifs.close();
	replace(argv, str);
	return 0;
}
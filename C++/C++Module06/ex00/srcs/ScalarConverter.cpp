#include "ScalarConverter.hpp"
#include <iostream>

// NOTES: ARRANGE THE .0 FOR THE FLOAT AND THE DECIMAL
// ARRANGE THE ELSE AFTER A PSEUDO 

using std::cout;
using std::endl;

static int get_Size(const std::string& literal)
{
	int size = literal.length();
	return size;
}

/*-----------------------Display--------------------------*/

static bool endsWithDotZero(const std::string& str)
{
    size_t length = str.length();

    if (length >= 2 && str[length - 2] == '.' && str[length - 1] == '0')
        return true;
    return false;
}

static bool endsWithDotZeroF(const std::string& str)
{
    size_t length = str.length();

    if (length >= 3  && str[length - 3] == '.' && str[length - 2] == '0' && str[length - 1] == 'f')
        return true;
    return false;
}

void displayAsciiCharacter(int value)
{
    if (value >= 32 && value <= 126) {
        // Displayable ASCII character
        char asciiChar = static_cast<char>(value);
        cout << "char: '" << asciiChar << "'" << endl;
    }
	else 
        cout << "char: Non Displayable" << endl;
}

void displayAsciiValue(char character)\
{
    int asciiValue = static_cast<int>(character);
    cout << "int: " << asciiValue << endl;
    cout << "float: " << asciiValue << ".0f" << endl;
    cout << "int: " << asciiValue << ".0" <<endl;
}

/*---------------------detect the type------------------------------------*/

static bool isInt(const std::string& literal)
{
	int i = 0;
	if (literal[i] == '-')
		i++;
	while (literal[i])
	{
		if ((literal[i] < '0' || literal[i] > '9'))
			return 0;
		i++;
	}
	return 1;
}

static bool isOneChar(const std::string& literal)
{
	int size = get_Size(literal);
	if (size > 1)
		return 0;
	else if ('0' <= literal[0] && literal[0] <= '9')
		return 0;
	return 1;
}

static bool isFloat(const std::string& literal)
{
	int i = 0, countComma = 0;
	if (literal[i] == '-')
		i++;
	int size = get_Size(literal);
	while (literal[i])
	{
		if (literal[i] == '.')
			countComma++;
		if (countComma > 1)
			return 0;
		if ((literal[i] < '0' || literal[i] > '9') && literal[i] != '.' && literal[size - 1] != 'f')
			return 0;
		i++;
	}
	if (literal[size - 1] == 'f' && countComma == 1)
		return 1;
	return 0;
}

static bool isDouble(const std::string& literal)
{
	int i = 0, countComma = 0;
	if (literal[i] == '-')
		i++;
	int size = get_Size(literal);
	while (literal[i])
	{
		if (literal[i] == '.')
			countComma++;
		if (countComma > 1)
			return 0;
  		if ((literal[i] < '0' || literal[i] > '9') && literal[i] != '.' && literal[size - 1] == 'f')
		{
			return 0;
		}
		i++;
	}
	if (countComma == 1)
		return 1;
	return 0;
}

static const char* isDoublePseudoLiterals(const std::string& literal) // without the f: -inf, +inf, nan
{
	if (literal == "-inf")
		return "-inf";
	else if (literal == "+inf")
		return "+inf";
	else if (literal == "nan")
		return "nan";
	else
		return 0;
}

static const char* isFloatPseudoLiterals(const std::string& literal) // with the f: -inff, +inff, nanf
{
	if (literal == "-inff")
		return "-inff";
	else if (literal == "+inff")
		return "+inff";
	else if (literal == "nanf")
		return "nanf";
	else
		return 0;
}

/*-----------------------transforming from the actual string to the type--------------------------*/

static long int ft_stoi(const std::string& literal)
{
	long int num;
	std::stringstream ss(literal);

	ss >> num;
	return num;
}

static double ft_stod(const std::string& literal)
{
	double num;
	std::stringstream ss(literal);

	ss >> num;
	return num;
}

static float ft_stof(const std::string& literal)
{
	float num;
	std::stringstream ss(literal);

	ss >> num;
	return num;
}

/*-----------------------convert function---------------------------*/

void ScalarConverter::convert(const std::string& literal)
{
	bool isCondition = 0;
	const char *doublePseudo;
	doublePseudo = isDoublePseudoLiterals(literal); // -inf, +inf, nan
	if (doublePseudo)
	{
		isCondition = 1;
		cout << "char: impossible" << endl;
		cout << "int: impossible" << endl;
		cout << "float: " << doublePseudo << 'f' << endl;
		cout << "double: " << doublePseudo << endl;
	}

	const char *floatPseudo;
	floatPseudo = isFloatPseudoLiterals(literal);
	if (floatPseudo)
	{
		isCondition = 1;
		cout << "char: impossible" << endl;
		cout << "int: impossible" << endl;
		cout << "float: " << floatPseudo << endl;
		if (literal == "-inff")
			cout << "double: " << "-inf" << endl;
		if (literal == "+inff")
			cout << "double: " << "+inf" << endl;
		if (literal == "nanf")
			cout << "double: " << "nan" << endl;
	}

	if(isInt(literal))
	{
		isCondition = 1;
		long int num = ft_stoi(literal);
    	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		{
        	std::cerr << "Error: Conversion from double to int would result in overflow." << std::endl;
        	return ;
		}
		displayAsciiCharacter(num);
		cout << "int: " << num << endl;
		cout << "Float: " << num << ".0f" << endl;
		cout << "Double: " << num << ".0" << endl;
	}

	if (isOneChar(literal))
	{
		isCondition = 1;
		cout << "char: '" << literal[0] << "'"<< endl;
		displayAsciiValue(literal[0]);
	}
	
	if (isFloat(literal))
	{
		isCondition = 1;
		int intNum = ft_stoi(literal);
		displayAsciiCharacter(intNum);
		cout << "int: " << intNum << endl;
		float num = ft_stof(literal);
		if (endsWithDotZeroF(literal))
			cout << "Float: " << num << ".0f" << endl;
		else
			cout << "Float: " << num << "f" << endl;
		if (endsWithDotZeroF(literal))
			cout << "Double: " << num << ".0" << endl;
		else 
			cout << "Double: " << num << endl;
	}

	if (isDouble(literal))
	{
		isCondition = 1;
		long int intNum = ft_stoi(literal);
    	if (intNum > std::numeric_limits<int>::max() || intNum < std::numeric_limits<int>::min())
		{
        	std::cerr << "Error: Conversion from double to int would result in overflow." << std::endl;
        	return ;
		}
		displayAsciiCharacter(intNum);
		cout << "int: " << intNum << endl;
		long double num = ft_stod(literal);
		if (endsWithDotZero(literal))
			cout << "Float: " << num << ".0f" << endl;
		else
			cout << "Float: " << num << "f" << endl;
		if (endsWithDotZero(literal))
			cout << "Double: " << num << ".0" << endl;
		else 
			cout << "Double: " << num << endl;
	}

	if (isCondition == 0)
		cout << "Error: The input is not valid for conversion to int, char, float, or double." << std::endl;
}
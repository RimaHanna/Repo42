#include "ScalarConverter.hpp"
#include <iostream>

// NOTES: ARRANGE THE .0 FOR THE FLOAT AND THE DECIMAL
// ARRANGE THE ELSE AFTER A PSEUDO 

using std::cout;
using std::endl;

// Detect the type of the literal
	// type int
	// type one char
	// type pseudo literals

static int get_Size(const std::string& literal)
{
	int size = literal.length();
	return size;
}

void displayAsciiCharacter(int value) {
    if (value >= 32 && value <= 126) {
        // Displayable ASCII character
        char asciiChar = static_cast<char>(value);
        cout << "char: '" << asciiChar << "'" << endl;
    } else {
        // Non-displayable ASCII character
        cout << "char: Non Displayable" << endl;
    }
}

void displayAsciiValue(char character) {
    int asciiValue = static_cast<int>(character);
    cout << "int: " << asciiValue << endl;
    cout << "float: " << asciiValue << ".0f" << endl;
    cout << "int: " << asciiValue << ".0" <<endl;

}

/*---------------------checking what type------------------------------------*/

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
			return 0;
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

static int ft_stoi(const std::string& literal)
{
	int num;
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

void ScalarConverter::convert(const std::string& literal)
{
	const char *doublePseudo;
	doublePseudo = isDoublePseudoLiterals(literal); // -inf, +inf, nan
	if (doublePseudo)
	{
		cout << "char: impossible" << endl;
		cout << "int: impossible" << endl;
		cout << "float: " << doublePseudo << 'f' << endl;
		cout << "double: " << doublePseudo << endl;
	}

	const char *floatPseudo;
	floatPseudo = isFloatPseudoLiterals(literal);
	if (floatPseudo)
	{
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

	/*-------------------------------------------------------*/

	if(isInt(literal))
	{
		cout << "isInt" << endl;
		int num = ft_stoi(literal);
		displayAsciiCharacter(num);
		cout << "int: " << num << endl;
		cout << "Float: " << num << ".0f" << endl;
		cout << "Double: " << num << ".0" << endl;

	}

	else if (isOneChar(literal))
	{
		cout << "isOnechar" << endl;
		cout << "char: '" << literal[0] << "'"<< endl;
		displayAsciiValue(literal[0]);
	}
	

	else if (isFloat(literal))
	{
		cout << "isFloatNumber" << std::endl;
		int intNum = ft_stoi(literal);
		displayAsciiCharacter(intNum);
		cout << "int: " << intNum << endl;
		float num = ft_stof(literal);
		cout << "Float: " << num << "f" << endl;
		cout << "Double: " << num << endl;

	}

	else if (isDouble(literal))
	{
		cout << "is Double Number" << std::endl;
		int intNum = ft_stoi(literal);
		displayAsciiCharacter(intNum);
		cout << "int: " << intNum << endl;
		double num = ft_stod(literal);
		cout << "Float: " << num << "f" << endl;
		cout << "Double: " << num << endl;
	}

	else
		cout << "Error: The input is not valid for conversion to int, char, float, or double." << std::endl;
}
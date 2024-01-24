#include "ScalarConverter.hpp"
#include <iostream>

using std::cout;
using std::endl;

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
		if (!isdigit(literal[i]))
			return false;
		i++;
	}
	return true;
}

static bool isOneChar(const std::string& literal)
{
	return literal.size() == 1 && !isdigit(literal[0]);
}

static bool isFloat(const std::string& literal)
{
    int i = 0, countComma = 0;
    if (literal[i] == '-')
        i++;
    int size = literal.size();
    while (literal[i])
    {
        if (literal[i] == '.')
            countComma++;
        if (countComma > 1)
            return false;
        if (!isdigit(literal[i]) && literal[i] != '.' && (i == size - 1 && literal[i] != 'f'))
            return false;
        i++;
    }
    if (i > 0 && literal[i - 1] == 'f' && countComma == 1)
        return true;
    return false;
}

static bool isDouble(const std::string& literal)
{
    int i = 0, countComma = 0;
    if (literal[i] == '-')
        i++;

    while (literal[i])
    {
        if (literal[i] == '.')
            countComma++;
        if (countComma > 1)
            return false;
        if (!isdigit(literal[i]) && literal[i] != '.')
            return false;
        i++;
    }
    if (countComma == 1)
        return true;
    return false;
}

static const char* isDoublePseudoLiterals(const std::string& literal)
{
    if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        return literal.c_str();
    }
    return 0;
}

static const char* isFloatPseudoLiterals(const std::string& literal) // with the f: -inff, +inff, nanf
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        return literal.c_str();
    }
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

void ScalarConverter::convert(const std::string& literal) {
    if (const char* doublePseudo = isDoublePseudoLiterals(literal)) {
        cout << "char: impossible\nint: impossible\nfloat: " << doublePseudo << "f\ndouble: " << doublePseudo << endl;
        return;
    }

    if (const char* floatPseudo = isFloatPseudoLiterals(literal)) {
        cout << "char: impossible\nint: impossible\nfloat: " << floatPseudo << endl;
        if (literal == "-inff") cout << "double: -inf\n";
        else if (literal == "+inff") cout << "double: +inf\n";
        else if (literal == "nanf") cout << "double: nan\n";
        return;
    }

    if (isInt(literal)) {
        long int num = ft_stoi(literal);
        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min()) {
            std::cerr << "Error: Conversion from double to int would result in overflow." << std::endl;
            return;
        }
        displayAsciiCharacter(num);
        cout << "int: " << num << "\nfloat: " << num << ".0f\ndouble: " << num << ".0\n";
        return;
    }

    if (isOneChar(literal)) {
        cout << "char: '" << literal[0] << "'\n";
        displayAsciiValue(literal[0]);
        return;
    }

    if (isFloat(literal)) {
        int intNum = ft_stoi(literal);
        displayAsciiCharacter(intNum);
        float num = ft_stof(literal);
        cout << "int: " << intNum << "\nfloat: ";
        if (endsWithDotZeroF(literal)) cout << num << ".0f\n";
        else cout << num << "f\n";
        cout << "double: ";
        if (endsWithDotZeroF(literal)) cout << num << ".0\n";
        else cout << num << endl;
        return;
    }

    if (isDouble(literal)) {
        long int intNum = ft_stoi(literal);
        if (intNum > std::numeric_limits<int>::max() || intNum < std::numeric_limits<int>::min()) {
            std::cerr << "Error: Conversion from double to int would result in overflow." << std::endl;
            return;
        }
        displayAsciiCharacter(intNum);
        long double num = ft_stod(literal);
        cout << "int: " << intNum << "\nfloat: ";
        if (endsWithDotZero(literal)) cout << num << ".0f\n";
        else cout << num << "f\n";
        cout << "double: ";
        if (endsWithDotZero(literal)) cout << num << ".0\n";
        else cout << num << endl;
        return;
    }

    cout << "Error: The input is not valid for conversion to int, char, float, or double." << std::endl;
}

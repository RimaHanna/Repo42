#include "BitcoinExchange.hpp"

unsigned int ft_stou(const std::string& str)
{
    unsigned int num;
    std::stringstream ss(str); // Allowing streaming operations on strings

    ss >> num; // Extract data from ss and store it in num
    return num;
}

float ft_stof(const std::string& str)
{
    float num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

BitcoinExchange::BitcoinExchange(void)
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    this->dataBase = other.dataBase;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

void BitcoinExchange::readFromCSVDatabase(std::ifstream& db)
{
    std::string line;
    size_t seperator;
    std::string rate;

    std::getline(db, line); // skip the first line since it is only the title
    while (std::getline(db, line)) // iterator over each line until no remaining lines
    {
        seperator = line.find(','); // return the position of the first occurence of coma
        rate = line.substr(seperator + 1); //  assign the value after the comma to rate 
        // set a new pair on the map <date, rate>
        this->dataBase[line.substr(0, seperator)] = ft_stof(rate); // extracts the date and rate information, and stores it in a dataBase map within the BitcoinExchange class
    }
    db.close();
}

float BitcoinExchange::getRateFromDatabase(const std::string& date)
{
    if (this->dataBase.count(date) > 0) // check if the date exists in the dataBase map. if the date exist it will count 1
        return this->dataBase.at(date); // return the rate at this date
    return (--this->dataBase.lower_bound(date))->second; // if date not found move to the move to the previous element in the containerand return it
}

bool BitcoinExchange::isDateCorrectFormat(const std::string& date)
{
	if (date.empty())
		return false;

 	size_t first_hyphen = date.find('-');
    size_t second_hyphen = date.find('-', first_hyphen + 1); // will skip the first Hyphen

	if (first_hyphen == std::string::npos || second_hyphen == std::string::npos
	||  date.find_first_not_of("0123456789.-") != std::string::npos)
	{
		std::cerr << "Error: bad input => " << "\"" << date << "\"" << '\n';
		return false;
	}
	return true;
}

// CHECK in DETAILS ............................
bool BitcoinExchange::isRateCorrectFormat(const std::string& rate)
{
	if (rate.empty() || rate.find_first_not_of("0123456789.-") != std::string::npos
	||  rate.at(0) == '.' || rate.find('.', rate.length() - 1) != std::string::npos)
		std::cerr << "Error: invalid rate => " << "\"" << rate << "\"" << '\n';
	else if (rate.at(0) == '-')
		std::cerr << "Error: not a positive number." << '\n';
	else if (rate.length() > 10 || (rate.length() == 10 && rate > "2147483647"))
		std::cerr << "Error: too large a number." << '\n';
	else
		return true;
	return false;

}

// CHECK in DETAILS ............................
bool BitcoinExchange::isValideDate(const std::string& date)
{
    	std::string s;
	int year, month, day;
	std::istringstream iss(date);
	int i = 0;

	while (std::getline(iss, s, '-'))
	{
		if (i == 0)
		{
			year = ft_stou(s);
			if (year < 2009 || year > 2022)
			{
				std::cerr << "Error: year is not at the database => " << "\"" << date << "\"" << '\n';
				return false;
			}
		}
		if (i == 1)
		{
			month = ft_stou(s);
			if (month < 1 || month > 12)
			{
				std::cerr << "Error: incorrect month => " << "\"" << date << "\"" << '\n';
				return false;
			}
		}
		if (i == 2)
		{
			day = ft_stou(s);
			if ((day < 1 || day > 31)
			||  (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
			||  (day > 28 && month == 2))
			{
				std::cerr << "Error: incorrect day => " << "\"" << date << "\"" << '\n';
				return false;
			}
		}
		i += 1;
	}
	if (i != 3)
	{
		std::cerr << "Error: incorrect date => " << "\"" << date << "\"" << '\n';
		return false;
	}
	return true;
}


#include "BitcoinExchange.hpp"

unsigned int ft_stou(const std::string& str);

float ft_stof(const std::string& str);

int errorOccur(std::string str)
{
    std::cerr << str << std::endl;
    return 1;
}

int main(int argc, char **argv)
{
    (void) argv;
    if (argc != 2)
        return errorOccur ("error: invalid number of arguments");

    // ifstream: input file stream used to read data from files.
    // std::ifstream::in : indicate the mode in which the file should be opened, in this case it is input(reading)
    std::ifstream inputFile(argv[1], std::ifstream::in);
    if (!inputFile.is_open())
        return errorOccur("error: the argument provided is not a valid input file");

    std::ifstream CSVFile("./data.csv", std::ifstream::in);
    if (!CSVFile.is_open())
        return errorOccur("error: could not open csv file");

    BitcoinExchange btc;
    btc.readFromCSVDatabase(CSVFile);

	std::string line;
    std::getline(inputFile, line); // skip the first line
    while (std::getline(inputFile, line))
    {
        size_t seperator = line.find('|');
		if (seperator == std::string::npos
		||	line.length() < seperator + 2)
		{
			std::cerr << "Error: bad input => " <<  line << '\n';
			continue ;
		}

		std::string date = line.substr(0, seperator - 1);
		if (!btc.isDateCorrectFormat(date) || !btc.isValideDate(date))
			continue;

        std::string valueFromInputFile = line.substr(seperator + 2);
		if (!btc.isValueRateCorrectFormat(valueFromInputFile))
			continue;
		float rate = ft_stof(valueFromInputFile);

	    std::cout << date << " => " << rate << " = " << std::setprecision(2) << rate * btc.getRateFromDatabase(date) << std::endl;
    }
    inputFile.close();
    CSVFile.close();
    return 0;
}

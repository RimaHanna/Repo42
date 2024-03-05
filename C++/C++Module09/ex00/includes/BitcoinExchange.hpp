#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <sstream> // for stringstream
#include <iostream>
#include <fstream> // for ifstream 
#include <iomanip> // setprecision(#ofdecimal)

class BitcoinExchange
{
	private:
		std::map<std::string, float> dataBase;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange(void);
		void readFromCSVDatabase(std::ifstream& db);
		float getRateFromDatabase(const std::string& date);
		bool isDateCorrectFormat(const std::string& date);
		bool isRateCorrectFormat(const std::string& rate);
		bool isValideDate(const std::string& date);
};

#endif
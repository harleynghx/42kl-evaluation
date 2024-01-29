#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
	std::ifstream dataFile;
	dataFile.open("data.csv");
	if (!dataFile.is_open())
	{
		std::cerr << "Error: No data.csv file found.\n";
		return;
	}

	std::string buffer;
	std::getline(dataFile, buffer);
	if (buffer != "date,exchange_rate")
	{
		std::cerr << "Invalid data.csv file. (wrong format)\n";
		return;
	}

	while (std::getline(dataFile, buffer))
	{
		std::string::size_type splitpos = buffer.find(",");
		if (splitpos >= buffer.size())
		{
			std::cerr << "Error: bad input => " << buffer << "\n";
			continue;
		}

		std::string date = buffer.substr(0, splitpos);
		if (!BitcoinExchange::CheckDate(date))
		{
			std::cerr << "Error: bad date => " << buffer << "\n";
			continue;
		}

		std::stringstream sval(buffer.substr(splitpos + 1));
		double val = 0;
		sval >> val; // this is apparently a way to convert string to double (stod is not part of c++98)
		_Data[date] = val;
	}

	dataFile.close();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& bitcoin)
{
	_Data = bitcoin._Data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& bitcoin)
{
	_Data = bitcoin._Data;
	return *this;
}

double BitcoinExchange::GetData(std::string date) const
{
	// if data.csv was not loaded, return 0
	if (_Data.size() == 0)
		return 0;

	std::map<std::string, double>::const_iterator it = _Data.lower_bound(date);
	// std::cout << "before: " << it->first << "\n";
	if (it != _Data.begin() && it->first != date) // prefer to round down instead of rounding up
		--it;

	// std::cout << "after: " << it->first << "\n";
	return it->second;
}

bool BitcoinExchange::CheckDate(std::string date)
{
	if (date.length() != 10)
		return false;

	std::string::iterator it = date.begin();
	for (int i = 0; i < 4; i++)
	{
		if (*it < '0' || *it > '9')
			return false;

		++it;
	}

	if (*it != '-')
		return false;

	++it;
	for (int i = 0; i < 2; i++)
	{
		if (*it < '0' || *it > '9')
			return false;

		++it;
	}

	if (*it != '-')
		return false;

	++it;
	for (int i = 0; i < 2; i++)
	{
		if (*it < '0' || *it > '9')
			return false;

		++it;
	}

	return true;
}

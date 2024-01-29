#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << argv[0] << " <data>" << std::endl;
		return 1;
	}

	BitcoinExchange bitcoin;
	std::ifstream file;

	file.open(argv[1]);
	if (!file.is_open())
	{
		std::cerr << "Error: Unable to open file " << argv[1] << "\nExiting..." << std::endl;
		return 1;
	}

	std::string buffer;
	std::getline(file, buffer);
	if (buffer != "date | value")
	{
		std::cerr << "Error: bad file header => " << buffer << "\n";
		return 1;
	}

	while (std::getline(file, buffer))
	{
		std::string::size_type splitpos = buffer.find(" | ");
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

		std::stringstream sval(buffer.substr(splitpos + 3));
		double val = 0;
		sval >> val; // this is apparently a way to convert string to double (stod is not part of c++98)
		if (val < 0)
		{
			std::cerr << "Error: not a positive number\n";
			continue;
		}
		else if (val > 1000)
		{
			std::cerr << "Error: too large a number\n";
			continue;
		}

		std::cout << date << " => " << val << " = " << val * bitcoin.GetData(date) << "\n";
	}
}
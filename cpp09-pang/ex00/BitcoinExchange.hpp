#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& bitcoin);
	BitcoinExchange& operator=(const BitcoinExchange& bitcoin);

	double GetData(std::string date) const;
	static bool CheckDate(std::string date);

private:
	std::map<std::string, double> _Data;
};

#endif

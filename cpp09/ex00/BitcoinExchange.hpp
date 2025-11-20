#pragma once

#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>

class BitcoinExchange
{
private:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &other);
public:
	static void mapping(const std::string &filename);
};
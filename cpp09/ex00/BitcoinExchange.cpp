#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	return *this;
}

void readCsv(std::map<std::string, double> &data, const std::string &filename)
{
	std::string key_val;
	std::string data_date;
	double data_value;
	size_t data_pos;
	std::ifstream data_input;

	data_input.open(filename.c_str());
	if (!data_input)
		throw std::runtime_error("Error: open failed");
	getline(data_input, key_val);
	while(getline(data_input, key_val))
	{
		if (key_val.empty())
			continue;
		data_pos = key_val.find(",");
		data_date = key_val.substr(0, data_pos);
		data_value = std::atof(key_val.substr(data_pos + 1).c_str());
		data.insert(std::make_pair(data_date, data_value));
	}
	// for (std::map<std::string, double>::iterator it = data.begin(); it != data.end(); it++)
	// {
	// 	std::cout << it->first << " "<< it->second << std::endl;
	// }
	data_input.close();
}

double ft_check_value(const std::string &value)
{
	double res;
	res = std::atof(value.c_str());
	if (res < 0)
		throw std::runtime_error("Error: not a positive number");
	if (res > 1000)
		throw std::runtime_error("Error: value too large");
	return res;
}

void ft_check_date(const std::string &date)
{
	int year;
	int month;
	int day;
	int pos;

	pos = date.find("-");
	year = atoi(date.substr(0, pos).c_str());
	month = atoi(date.substr(pos +1, pos+3).c_str());
	day = atoi(date.substr(pos +4, pos+6).c_str());
	if (month > 12 || month < 1 || year < 0 || day < 0)
		throw std::runtime_error("Error: wrong date");
	int max_days;
	switch(month)
	{
		case 2:
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
				max_days = 29;
			else
				max_days = 28;
			break;
		case 4: case 6: case 9: case 11:
			max_days = 30;
		default:
			max_days = 31;
	}
	if (day > max_days)
		throw std::runtime_error("Error: wrong date");
}

double valueConverted(double value, std::string date, std::map<std::string, double> &data)
{
	double last_save = 0;

	std::map<std::string, double>::iterator it;
	for (it = data.begin(); it != data.end(); it++)
	{
	
		// std::cout <<"TEST1::'" << it->first << "'" << date<< std::endl;
		if (it->first > date)
		{
			// std::cout <<"TEST2::'" << it->first << "'" << date<< std::endl;
			return (last_save);
		}
		last_save = value * it->second;
	}

	return (last_save);
}

void readInput(const std::string &filename, std::map<std::string, double> &data)
{
	std::ifstream input;
	input.open(filename.c_str());
	if (!input)
		throw std::runtime_error("Error: open failed");
	std::string tab_key_val;
	std::string tab_date;
	std::string tab_value_str;
	double tab_value;
	double convertedvalue;
	size_t tab_pos;

	while(getline(input, tab_key_val))
	{
		if (tab_key_val.empty())
			continue;
		if (tab_key_val == "date | value")
			continue;
		tab_pos = tab_key_val.find("|");
		if (tab_pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << tab_key_val << std::endl;
			continue;
		}
		try
		{
			tab_date = tab_key_val.substr(0, tab_pos);
			ft_check_date(tab_date);
			tab_value_str = tab_key_val.substr(tab_pos + 1);
			tab_value = ft_check_value(tab_value_str);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			continue;
		}
		tab_pos = tab_date.find(" ");
		if(tab_pos != std::string::npos)
		{
			tab_date = tab_date.substr(0, tab_pos);
		}
		convertedvalue = valueConverted(tab_value, tab_date, data);
		// std::cout << std::fixed;
		// std::cout << std::setprecision(2);
		std::cout << tab_date << "=> " << tab_value << " = " << convertedvalue << std::endl;
		// std::cout << std::scientific;
	}
	input.close();
}

void BitcoinExchange::mapping(const std::string &filename)
{
	std::map<std::string, double> data;
	
	readCsv(data, "data.csv");

	readInput(filename, data);
}
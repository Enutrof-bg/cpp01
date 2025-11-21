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

int isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
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
	for(std::string::const_iterator it = value.begin(); it != value.end(); it++)
	{
		if (isDigit(*it) == 1 && *it != ' ' && *it != '.')
			throw std::runtime_error("Error: non numeric value => " + value);
	}
	return res;
}

// trim from end of string (right)
inline std::string& rtrim(std::string& s, const char* t)
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from beginning of string (left)
inline std::string& ltrim(std::string& s, const char* t)
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from both ends of string (right then left)
inline std::string& trim(std::string& s, const char* t)
{
    return ltrim(rtrim(s, t), t);
}
std::string ft_trim_str(std::string &tab_date)
{
	trim(tab_date, " ");
	for(std::string::iterator it = tab_date.begin(); it != tab_date.end(); it++)
	{
		if (isDigit(*it) == 1 && *it != ' ' && *it != '-')
			throw std::runtime_error("Error: Unauthorized char for date => " + tab_date);
	}
	for(std::string::iterator it = tab_date.begin(); it != tab_date.end(); it++)
	{
		if ((isDigit(*it) == 0 ||  *it == '-') && ((isDigit(*(it + 1))) == 1 && (*(it + 1) != '-') && *(it+1)!='\0'))
			throw std::runtime_error("Error: Unauthorized char for date => " + tab_date);
	}
	return tab_date;
}

void ft_check_date(const std::string &date)
{
	int year;
	int month;
	int day;
	size_t pos;
	size_t pos2;

	if (date.size() != 10)
		throw std::runtime_error("Error: date invalid YYYY-MM-DD => " + date);
	pos = date.find("-");
	if (pos != 4)
		throw std::runtime_error("Error: date invalid YYYY-MM-DD => " + date);
	pos2 = date.find("-", pos + 1);
	if (pos2 != 7)
		throw std::runtime_error("Error: date invalid YYYY-MM-DD => " + date);

	year = atoi(date.substr(0, pos).c_str());
	month = atoi(date.substr(pos +1, pos2).c_str());
	day = atoi(date.substr(pos2+1, pos2+2).c_str());
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
	double last_save = -1;

	std::map<std::string, double>::iterator it;
	for (it = data.begin(); it != data.end(); it++)
	{
		if (it->first > date)
		{
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
			ft_trim_str(tab_date);
			ft_check_date(tab_date);
			tab_value_str = tab_key_val.substr(tab_pos + 1);
			tab_value = ft_check_value(tab_value_str);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			continue;
		}
	
		// try
		// {
			convertedvalue = valueConverted(tab_value, tab_date, data);
			if (convertedvalue == -1)
				std::cout << "Error: anterior date => " << tab_date << std::endl;
			else
				std::cout << tab_date << " => " << tab_value << " = " << convertedvalue << std::endl;
		// }
		// catch(std::exception &e)
		// {
		// 	std::cout << e.what() << std::endl;
		// }
		// std::cout << std::fixed;
		// std::cout << std::setprecision(2);
		
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

//todo: afficher correctement notation avec 2 decimal
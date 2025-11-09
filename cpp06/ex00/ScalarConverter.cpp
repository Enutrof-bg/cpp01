#include "ScalarConverter.hpp"

int isDigit(const std::string &str)
{
	int i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i]<= '9'))
			return (1);
		i++;
	}
	return (0);
}

void convertChar(const std::string &str)
{
	(void)str;
	char c;

	c = atoi(str.c_str());
	std::cout << "char: '" << c << "'" << std::endl;
}

void convertInt(std::string str)
{
	(void)str;
	int x;
	if (str.size() == 1)
	{
		x = str[0];
		std::cout << "int: "<< x << std::endl;
	}
	else if (isDigit(str) == 0)
	{
		x = atoi(str.c_str());
		std::cout << "int: "<< x << std::endl;
	}
	else
	{
		x = atoi(str.c_str());
		std::cout << "int: "<< " impossible" << std::endl;
	}
}

void convertFloat(const std::string &str)
{
	(void)str;
	int x = atoi(str.c_str());
	std::cout << x << std::endl;
}

void convertDouble(const std::string &str)
{
	(void)str;

	std::cout << str << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	convertChar(str);

	convertInt(str);
	// char _char = atoi(str.c_str());
	// int _int = atoi(str.c_str());
	// float _float = atof(str.c_str());
	// double _double = atof(str.c_str());

	// std::cout << _char << std::endl;
	// std::cout << _int << std::endl;
	// std::cout << _float << "f" << std::endl;
	// std::cout << _double << std::endl;

	// std::cout << inf << std::endl;
}
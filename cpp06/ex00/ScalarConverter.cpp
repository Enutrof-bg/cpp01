#include "ScalarConverter.hpp"

int isDot(std::string str)
{
	int dot = 0;
	int i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		i++;
	}
	return (dot);
}

int isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

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

int nbrDigit(std::string str)
{
	int i = 0;
	int digit = 0;
	while (str[i])
	{
		if (isDigit(str[i]) == 0)
			digit++;
		i++;
	}
	return (digit);
}

void convertChar(const std::string &str)
{
	(void)str;
	char c = '0';

	if (str.size() == 1)
		c = str[0];
	else if (str.size() == 3)
		c = str[1];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" <<std::endl;
}

void convertInt(std::string str)
{
	(void)str;
	int x = atoi(str.c_str());
	char c = x;
	if (c < 32 || c > 126)
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << x << std::endl;
	std::cout << "float: " << static_cast<float>(x) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(x) << ".0" <<std::endl;
}

void convertFloat(const std::string &str)
{
	(void)str;
	float val_x = atof(str.c_str());
	char c = val_x;
	if (c < 32 || c > 126)
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(val_x) << std::endl;
	if (val_x - (int)val_x == 0)
	{
		std::cout << "float: " << static_cast<float>(val_x) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(val_x) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(val_x) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(val_x) << std::endl;
	}
}

void convertDouble(const std::string &str)
{
	(void)str;
	float val_x = atof(str.c_str());
	char c = val_x;

	if (c < 32 || c > 126)
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(val_x) << std::endl;

	if (val_x - (int)val_x == 0)
	{
		std::cout << "float: " << static_cast<float>(val_x) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(val_x) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(val_x) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(val_x) << std::endl;
	}
	
}

int isChar(std::string str)
{
	if (str.size() == 1 && isDigit(str[0]) == 1)
	{
		return (0);
	}
	else if (str.size() == 3 && str[0] == '\'' && str[2] == '\'')
	{
		return (0);
	}
	return (1);
}

int isInt(std::string str)
{
	int i = 0;
	if (isDot(str) != 0)
		return (1);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (isDigit(str[i]) == 1)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int isFloat(std::string str)
{
	int i = 0;
	if (nbrDigit(str) <= 0)
		return (1);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (isDigit(str[i]) == 1 && str[i] != '.')
			return (1);
		if (str[i] == '.')
		{
			i++;
			while (str[i])
			{
				if (str[i] == 'f' && str[i + 1] == '\0')
					return (0);
				if (isDigit(str[i]) == 1)
					return (1);
				i++;
			}
		}
		i++;
	}
	if (str[i - 1] == 'f' && str[i] == '\0')
		return (0);
	return (1);
}

int isDouble(std::string str)
{
	int i = 0;
	if (isDot(str) != 1)
		return (1);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (isDigit(str[i]) == 1 && str[i] != '.')
			return (1);
		i++;
	}
	return (0);
}

int isElse(std::string str)
{
	if (str == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanff" << std::endl;
		std::cout << "double: nanf" << std::endl;
	}
	return (0);
}

void ScalarConverter::convert(std::string str)
{
	(void)str;
	// float f = .5f;
	// std::cout << static_cast<int>(f) << std::endl;
	// std::cout << static_cast<double>(f) << std::endl;

	if (isChar(str) == 0)
	{
		std::cout << "Char" << std::endl;
		convertChar(str);
	}
	else if (isInt(str) == 0)
	{
		std::cout << "Int" << std::endl;
		convertInt(str);
	}
	else if (isFloat(str) == 0)
	{
		std::cout << "Float" << std::endl;
		convertFloat(str);
	}
	else if (isDouble(str) == 0)
	{
		std::cout << "Double" << std::endl;
		convertDouble(str);
	}
	else
	{
		std::cout << "Autre" << std::endl;
		isElse(str);
	}
}
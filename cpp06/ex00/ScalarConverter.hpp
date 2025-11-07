#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &other);

public:
	static void convert(std::string str);
};
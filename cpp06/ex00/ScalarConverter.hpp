#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <math.h>

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
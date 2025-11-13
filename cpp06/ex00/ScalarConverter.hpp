#pragma once

#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
#include <stdlib.h>
#include <iomanip>
#include <math.h>

// #define D_INT_MAX std::numeric_limits<int>::max()
// #define D_INT_MIN std::numeric_limits<int>::min()

// #define D_FLOAT_MAX std::numeric_limits<float>::max()
// #define D_FLOAT_MIN std::numeric_limits<float>::min()

// #define D_DOUBLE_MAX std::numeric_limits<double>::max()
// #define D_DOUBLE_MIN std::numeric_limits<double>::min()

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
#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
	char _char = atoi(str.c_str());
	int _int = atoi(str.c_str());
	float _float = atof(str.c_str());
	double _double = atof(str.c_str());

	std::cout << _char << std::endl;
	std::cout << _int << std::endl;
	std::cout << _float << "f" << std::endl;
	std::cout << _double << std::endl;

	// std::cout << inf << std::endl;
}
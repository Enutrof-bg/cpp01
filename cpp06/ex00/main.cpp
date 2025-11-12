#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of argument" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);

	//Test exemple
	// int a = 10;
	// char c = 'a';
	// (void)a;
	// (void)c;

	// int *q = (int *)&a;
	// int *q = (int*)&c;
	// int *p = static_cast<int *>(&c);
	// (void)q;
	// (void)p;
	// std::cout << *q << std::endl;

	return (0);
}
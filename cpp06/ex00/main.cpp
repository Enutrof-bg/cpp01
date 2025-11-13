#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Wrong number of argument" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	// std::cout << "Test1" <<  std::endl;
	// ScalarConverter::convert("42");

	// std::cout << "\nTest2" <<  std::endl;
	// ScalarConverter::convert("42.2");

	// std::cout << "\nTest3" <<  std::endl;
	// ScalarConverter::convert("42.0f");

	// std::cout << "\nTest4" <<  std::endl;
	// ScalarConverter::convert("42.0");

	// std::cout << "\nTest5" <<  std::endl;
	// ScalarConverter::convert("42.2f");

	// std::cout << "\nTest6" <<  std::endl;
	// ScalarConverter::convert("2147483647");

	// std::cout << "\nTest7" <<  std::endl;
	// ScalarConverter::convert("2147483648");

	// std::cout << "\nTest8" <<  std::endl;
	// ScalarConverter::convert("2147483411");

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
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: filename excepted" << std::endl;
		return (1);
	}

	try
	{
		std::string filename(argv[1]);
		BitcoinExchange::mapping(filename);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
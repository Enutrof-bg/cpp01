#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Erreur: 2 arg excepted 💩" << std::endl;
		return (1);
	}
	
	double res;
	try
	{
		res = RPN::calculate(argv[1]);
		std::cout << res << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
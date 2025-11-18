#include "PmergeMe.hpp"

int isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}
int ft_check_arg(int argc, char **argv)
{
	int i = 1;
	size_t j = 0;
	while (i < argc)
	{
		while (j < strlen(argv[i]))
		{
			if (argv[i][0] == '+')
				j++;
			if (isDigit(argv[i][j]) == 1)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Error: no argument 💩" << std::endl;
		return (1);
	}
	if (ft_check_arg(argc, argv) == 1)
	{
		std::cout << "Error: wrong arg, please positive int only 💩" << std::endl;
		return (1);
	}

	// PmergeMeDeque d1(argv);
	PmergeMeVector v1(argv);
	v1.ft_print();
	v1.ft_merge();
	
	std::cout << "GOOD" << std::endl;
	return (0);
}
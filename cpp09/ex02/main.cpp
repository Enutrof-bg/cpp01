#include "PmergeMe.hpp"
#include "PmergeMeDeque.hpp"

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

	std::clock_t start;
	double duration_vector;

	start = std::clock();
	
	PmergeMeVector vec1(argv);
	std::cout << "Before:";
	// vec1.ft_print(vec1.getArr());
	std::cout << std::endl;

	std::vector<int> result_vector = vec1.ft_merge(vec1.getArr());

	std::cout << "After:";
	// vec1.ft_print(vec1.getArr());
	std::cout << std::endl;

	duration_vector = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	// std::cout << std::fixed << "Time vector:" <<duration_vector << std::endl;



	std::clock_t start_deque;
	double duration_deque;

	start_deque = std::clock();
	
	PmergeMeDeque deq1(argv);
	std::cout << "Before:";
	// deq1.ft_print(deq1.getArr());
	std::cout << std::endl;

	std::deque<int> result_deque = deq1.ft_merge(deq1.getArr());

	std::cout << "After:";
	// deq1.ft_print(deq1.getArr());
	std::cout << std::endl;

	duration_deque = (std::clock() - start_deque) / (double)CLOCKS_PER_SEC;



	std::cout << std::fixed << "Time vector:" <<duration_vector << std::endl;
	std::cout << std::fixed <<"Time deque:" << duration_deque << std::endl;

	return (0);
}
#include "PmergeMe.hpp"

PmergeMeVector::PmergeMeVector(char **argv)
{
	init_tab(argv);
}

PmergeMeVector::~PmergeMeVector()
{}

void PmergeMeVector::init_tab(char **argv)
{
	int val;

	for (int i = 1; argv[i] != NULL; i++)
	{
		val = atoi(argv[i]);
		v1.push_back(val);
	}
}

void PmergeMeVector::ft_print()
{
	for(std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		std::cout << *it;		
	}
	std::cout << std::endl;
}

void PmergeMeVector::ft_merge()
{
	
}
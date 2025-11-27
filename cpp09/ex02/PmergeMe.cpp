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
		std::cout << *it << std::endl;		
	}
	std::cout << std::endl;
}
std::vector<int> PmergeMeVector::getArr()
{
	return v1;
}
std::vector<int> ft_merge(std::vector<int> arr)
{
	if (arr.size() <= 1)
		return arr;
	int reste = -1;
	std::vector<std::pair<int,int> > pair;
	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		int a = arr[i];
		int b = arr[i + 1];
		if (a < b)
			pair.push_back(std::make_pair(b, a));
		else
			pair.push_back(std::make_pair(a, b));
	}
	if (arr.size() % 2 == 1)
		reste = arr.back();

	for (std::vector<std::pair<int, int> >::iterator it = pair.begin();
		it != pair.end();it++)
	{
		std::cout << it->first << ", "<< it->second << std::endl;
	}
	std::cout << reste << std::endl;

	
	return arr;
}
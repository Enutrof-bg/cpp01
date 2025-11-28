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

void ft_print_pair(std::vector<std::pair<int,int> > pair, int reste)
{
	for (std::vector<std::pair<int, int> >::iterator it = pair.begin();
		it != pair.end();it++)
	{
		std::cout << it->first << ", "<< it->second << std::endl;
	}
	std::cout << reste << std::endl;
}

void ft_print(std::vector<int> vec)
{
	for (std::vector<int>::iterator it = vec.begin();
		it != vec.end();it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

bool ft_order(std::vector<int> arr)
{
	std::vector<int>::iterator it = arr.begin();
	it++;
	for(;it != arr.end(); it++)
	{
		if (*it < *(it - 1))
			return false;
	}
	return true;
}

std::vector<int> jacobsthal(int size)
{
	std::vector<int> jacob;
	std::vector<int> result;
	jacob.push_back(0);
	jacob.push_back(1);

	int i = 0;
	int next;
	int prev;
	while (i < size)
	{
		next = jacob[jacob.size() - 1] + (jacob[jacob.size() - 2] * 2);
		prev = jacob[jacob.size() - 1];
		jacob.push_back(next);
		i++;
	}

	for (size_t i = 1; i < jacob.size(); i++)
	{
		size_t now = jacob[i];
		size_t prev = jacob[i - 1];
		for(size_t j = now; j > prev; j--)
		{
			result.push_back(j);
		}
	}
	return result;
}


size_t ft_insert(std::vector<int> &main, int pend, size_t pos, int lvl)
{
	if (pos > main.size())
		pos = main.size() -1;
	if (lvl == 10)
		return pos;
	std::cout << "pos:"<< pos;
	std::cout << "comapre:" << main[pos];
	std::cout << "comapre:" << main[pos - 1] << std::endl;
	if (main[pos] > pend && pend > main[pos - 1])
	{
		// std::cout << "HAHAHAHAHAHAH" << std::endl;
		return pos;
		// std::cout << "HAHAHAHAHAHAH2" << std::endl;
	}
	else if (main[pos] > pend)
	{
		if (pos == 1 || pos == 0)
			return ft_insert(main, pend, pos - 1, lvl + 1);
		return (ft_insert(main, pend, pos - pos / 2, lvl + 1));
	}
	else
	{
		if (pos == 1 || pos == 0)
			return ft_insert(main, pend, pos + 1, lvl + 1);
		return (ft_insert(main, pend, pos + pos / 2, lvl + 1));
	}
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


	//refaire le sort sans la fonction std::sort //recursive??
	std::sort(pair.begin(), pair.end());

	

	std::vector<int> main;
	std::vector<int> pend;
	for(std::vector<std::pair<int,int> >::iterator it = pair.begin();
		it != pair.end(); it++)
	{
		main.push_back(it->first);
		pend.push_back(it->second);
	}
	if (reste != -1)
		pend.push_back(reste);
	ft_print(main);
	ft_print(pend);

	main.insert(main.begin(), pend[0]);
	ft_print(main);


	std::vector<int> jacob = jacobsthal(pend.size());
	ft_print(jacob);

	size_t index;
	std::cout << "jacob: ";
	for (size_t i = 1; i < pend.size(); i++)
	{
		index = jacob[i] - 1;
		std::cout << index << " " << pend[index] << "|" << std::endl;;
		int toinsert = pend[index];
		int pos = ft_insert(main, pend[index], index, 0);
		std::cout << "toinsert:" << pend[index] << std::endl;
		std::cout << "pos:" <<pos << std::endl;
		std::cout << "HAHAHAHAHAHAH" << std::endl;
		main.insert(main.begin() + pos, toinsert);
		// if (main[pos/2] > pend[index])
		// {

		// }
		std::cout << std::endl;
	
		ft_print(main);
	}
	std::cout << std::endl;

	ft_print(main);

	if (ft_order(main))
		std::cout << "GOOD" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	return arr;
}
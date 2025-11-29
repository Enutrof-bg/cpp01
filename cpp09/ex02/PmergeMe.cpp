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
std::vector<int> &PmergeMeVector::getArr()
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


void PmergeMeVector::ft_print(std::vector<int> vec)
{
	for (std::vector<int>::iterator it = vec.begin();
		it != vec.end();it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

bool PmergeMeVector::ft_order(std::vector<int> arr)
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

std::vector<int> jacobsthal(size_t size)
{
	std::vector<int> jacob;
	std::vector<int> result;
	jacob.push_back(0);
	jacob.push_back(1);

	size_t i = 0;
	int next;
	int prev;
	while (i < size && i < 25)
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
			if (j <= size)
				result.push_back(j);
		}
	}
	return result;
}

void merge_pair(std::vector<std::pair<int,int> >&pairs, size_t left, size_t mid, size_t right)
{
	std::vector<std::pair<int,int> > temp;

	size_t i = left;
	size_t j = mid + 1;
	// ft_print_pair(temp, 0);
	// std::cout << std::endl;
	while (i <= mid && j <= right)
	{
		if (pairs[i].first <= pairs[j].first)
		{
			temp.push_back(pairs[i]);
			i++;
		}
		else
		{
			temp.push_back(pairs[j]);
			j++;
		}
		// ft_print_pair(temp, 0);
		// std::cout << std::endl;
	}

	while (i <= mid)
	{
		temp.push_back(pairs[i]);
		i++;
	}

	while (j <= right)
	{
		temp.push_back(pairs[j]);
		j++;
	}

	// ft_print_pair(temp, 0);
	// std::cout << std::endl;

	for(size_t i = 0; i < temp.size(); i++)
	{	
		pairs[left + i] = temp[i];
	}
	// ft_print(pair);
	// ft_print_pair(pairs, 0);
	// std::cout << std::endl;
}

void merge_sort(std::vector<std::pair<int,int> >&pairs, size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;

		merge_sort(pairs, left, mid);
		merge_sort(pairs, mid + 1, right);
		merge_pair(pairs, left, mid, right);

		// ft_print_pair(pairs, 0);
		// std::cout << std::endl;
	}

}

size_t ft_insert(std::vector<int> &main, int pend, size_t pos)
{
	if (pos > main.size())
		pos = main.size();
	// if (lvl == 10)
		// return pos;

	size_t left = 0;
	size_t right = pos;

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;

		// std::cout << "comapre:" << left;
		// std::cout << "comapre:" << right << std::endl;
		if (main[mid] < pend)
			left = mid + 1;
		else
			right = mid;

		
	}
	return left;
	// std::cout << "pos:"<< pos;
	// std::cout << "comapre:" << main[pos];
	// std::cout << "comapre:" << main[pos - 1] << std::endl;
	// if (pend > main[main.size() - 1])
	// {
	// 	std::cout << "asdasdas" << std::endl;
	// 	return main.size()-1;
	// }
	// if (main[pos] > pend && pend > main[pos - 1])
	// {
	// 	std::cout << "HAHAHAHAHAHAH" << std::endl;
	// 	return pos;
	// 	// std::cout << "HAHAHAHAHAHAH2" << std::endl;
	// }
	// else if (main[pos] > pend)
	// {
	// 	if (pos == 1 || pos == 0)
	// 		return ft_insert(main, pend, pos - 1, lvl + 1);
	// 	return (ft_insert(main, pend, pos - (pos / 2), lvl + 1));
	// }
	// else
	// {
	// 	if (pos == 1 || pos == 0)
	// 		return ft_insert(main, pend, pos + 1, lvl + 1);
	// 	return (ft_insert(main, pend, pos + pos / 2, lvl + 1));

}


std::vector<int> PmergeMeVector::ft_merge(std::vector<int> &arr)
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

	// ft_print_pair(pair, reste);
	//refaire le sort sans la fonction std::sort //recursive??
	// std::sort(pair.begin(), pair.end());
	merge_sort(pair, 0, pair.size() -1);
	
	// ft_print_pair(pair, reste);


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

	// main.insert(main.begin(), pend[0]);
	// ft_print(main);


	std::vector<int> jacob = jacobsthal(pend.size());
	// std::cout << "suite de jacob:";
	// ft_print(jacob);

	main.insert(main.begin(), pend[0]);
	// ft_print(main);


	size_t index;
	
	for (size_t i = 1; i < pend.size(); i++)
	{
		// std::cout << "jacob: ";
		index = jacob[i] - 1;
		// if (index > pend.size())
			// index = jacob[]
		// std::cout << index << " " << pend[index] << "|" << std::endl;;
		int toinsert = pend[index];
		int max_pos = jacob[i] + i;
		int pos = ft_insert(main, toinsert, max_pos);
		// std::cout << "toinsert:" << pend[index] << std::endl;
		// std::cout << "pos:" <<pos << std::endl;
		// std::cout << "HAHAHAHAHAHAH" << std::endl;
		main.insert(main.begin() + pos, toinsert);
		// if (main[pos/2] > pend[index])
		// {

		// }
		// std::cout << std::endl;
	
		// ft_print(main);
	}
	// std::cout << std::endl;

	// ft_print(main);

	if (ft_order(main))
		std::cout << "GOOD" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	arr = main;
	return main;
}

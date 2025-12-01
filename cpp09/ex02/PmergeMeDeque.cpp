#include "PmergeMeDeque.hpp"

PmergeMeDeque::PmergeMeDeque(char **argv)
{
	init_tab(argv);
}

PmergeMeDeque::~PmergeMeDeque()
{}

void PmergeMeDeque::init_tab(char **argv)
{
	int val;

	for (int i = 1; argv[i] != NULL; i++)
	{
		val = atoi(argv[i]);
		v1.push_back(val);
	}
}

void PmergeMeDeque::ft_print()
{
	for(std::deque<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		std::cout << *it << std::endl;		
	}
	std::cout << std::endl;
}
std::deque<int> &PmergeMeDeque::getArr()
{
	return v1;
}

std::deque<int> PmergeMeDeque::getArr() const
{
	return v1;
}

void ft_print_pair(std::deque<std::pair<int,int> > pair, int reste)
{
	for (std::deque<std::pair<int, int> >::iterator it = pair.begin();
		it != pair.end();it++)
	{
		std::cout << it->first << ", "<< it->second << std::endl;
	}
	std::cout << reste << std::endl;
}


void PmergeMeDeque::ft_print(std::deque<int> vec)
{
	for (std::deque<int>::iterator it = vec.begin();
		it != vec.end();it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

bool PmergeMeDeque::ft_order(std::deque<int> arr)
{
	std::deque<int>::iterator it = arr.begin();
	it++;
	for(;it != arr.end(); it++)
	{
		if (*it < *(it - 1))
			return false;
	}
	return true;
}

std::deque<int> jacobsthal_deque(size_t size)
{
	std::deque<int> jacob;
	std::deque<int> result;
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

void merge_pair(std::deque<std::pair<int,int> >&pairs, size_t left, size_t mid, size_t right)
{
	std::deque<std::pair<int,int> > temp;
	size_t i = left;
	size_t j = mid + 1;

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
	for(size_t i = 0; i < temp.size(); i++)
	{	
		pairs[left + i] = temp[i];
	}
}

void merge_sort(std::deque<std::pair<int,int> >&pairs, size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;

		merge_sort(pairs, left, mid);
		merge_sort(pairs, mid + 1, right);
		merge_pair(pairs, left, mid, right);
	}
}

size_t ft_insert(std::deque<int> &main, int pend, size_t pos)
{
	if (pos > main.size())
		pos = main.size();
	size_t left = 0;
	size_t right = pos;

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;

		if (main[mid] < pend)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}


std::deque<int> PmergeMeDeque::ft_merge(std::deque<int> &arr)
{
	if (arr.size() <= 1)
		return arr;
	int reste = -1;

	std::deque<std::pair<int,int> > pair;
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


	merge_sort(pair, 0, pair.size() -1);


	std::deque<int> main;
	std::deque<int> pend;
	for(std::deque<std::pair<int,int> >::iterator it = pair.begin();
		it != pair.end(); it++)
	{
		main.push_back(it->first);
		pend.push_back(it->second);
	}
	if (reste != -1)
		pend.push_back(reste);


	std::deque<int> jacob = jacobsthal_deque(pend.size());


	main.insert(main.begin(), pend[0]);


	size_t index;
	for (size_t i = 1; i < pend.size(); i++)
	{
		index = jacob[i] - 1;
		int toinsert = pend[index];
		int max_pos = jacob[i] + i;
		int pos = ft_insert(main, toinsert, max_pos);
		main.insert(main.begin() + pos, toinsert);
	}


	if (ft_order(main))
		std::cout << "GOOD" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	arr = main;
	return main;
}

std::ostream &operator<<(std::ostream &out, const PmergeMeDeque &vec)
{
	std::deque<int> temp = vec.getArr();
	for(std::deque<int>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		if (it+1 == temp.end())
			out << *it;
		else
			out << *it << " ";		
	}
	return out;
}
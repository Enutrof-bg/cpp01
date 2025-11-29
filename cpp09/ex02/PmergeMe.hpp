#pragma once 

#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

template<typename T>
class PmergeMeVector
{
private:
	T v1;
	// std::deque<int> v2;
public:
	PmergeMeVector(char **argv);
	~PmergeMeVector();

	void init_tab(char **argv);
	void ft_print();
	// void ft_merge();
	T &getArr();

	T ft_merge(T &arr);
	bool ft_order(T arr);
	void ft_print(T vec);
};

// std::vector<int> ft_merge(std::vector<int> &arr);

// bool ft_order(std::vector<int> arr);

// void ft_print(std::vector<int> vec);

// template class PmergeVector<std::vector<int> >;

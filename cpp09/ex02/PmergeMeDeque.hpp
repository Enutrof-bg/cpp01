#pragma once 

#include <string>
#include <iostream>
#include <cstring>
#include <deque>
#include <deque>
#include <algorithm>
#include <ctime>


class PmergeMeDeque
{
private:
	std::deque<int> v1;
public:
	PmergeMeDeque(char **argv);
	~PmergeMeDeque();

	void init_tab(char **argv);
	void ft_print();
	std::deque<int> &getArr();

	std::deque<int> ft_merge(std::deque<int> &arr);
	bool ft_order(std::deque<int> arr);
	void ft_print(std::deque<int> vec);
};
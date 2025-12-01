#pragma once 

#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>


class PmergeMeVector
{
private:
	std::vector<int> v1;
public:
	PmergeMeVector(char **argv);
	~PmergeMeVector();

	void init_tab(char **argv);
	void ft_print();
	std::vector<int> &getArr();
	std::vector<int> getArr() const;

	std::vector<int> ft_merge(std::vector<int> &arr);
	bool ft_order(std::vector<int> arr);
	void ft_print(std::vector<int> vec);
};

std::ostream &operator<<(std::ostream &out, const PmergeMeVector &vec);

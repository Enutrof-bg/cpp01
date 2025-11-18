#pragma once 

#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>

// template <typename T>
// class PmergeMe
// {
// private:

// protected:
// 	T tab;
// public:
// 	static void init_tab(char **argv);
// };

// class PmergeMeVector : public PmergeMe<std::vector<int> >
// {
// private:

// public:
// 	PmergeMeVector(char **argv);
// 	~PmergeMeVector();
// };

// class PmergeMeDeque : public PmergeMe<std::deque<int> >
// {
// private:

// public:
// 	PmergeMeDeque(char **argv);
// 	~PmergeMeDeque();
// };

class PmergeMeVector
{
private:
	std::vector<int> v1;
public:
	PmergeMeVector(char **argv);
	~PmergeMeVector();

	void init_tab(char **argv);
	void ft_print();
	void ft_merge();
};
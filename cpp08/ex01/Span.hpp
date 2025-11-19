#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

class Span
{
private:
	unsigned int max;
	unsigned int nbrVal;
	std::vector<int> v1;
public:
	Span();
	Span(unsigned int n);
	~Span();
	Span(const Span &copy);
	Span &operator=(const Span &other);

	void addNumber(int val);
	size_t shortestSpan();
	size_t longestSpan();
	void addMember(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	void ft_print();

	

	class NumberFull : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
};
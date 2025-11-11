#pragma once

#include <iostream>
#include <string>
#include <vector>

class Span
{
private:
	std::vector<int> v1;
	unsigned int max;
	unsigned int nbrVal;
public:
	Span();
	Span(unsigned int n);
	~Span();
	Span(const Span &copy);
	Span &operator=(const Span &other);

	void addNumber(int val);
	// int shortestSpan();
	// int longestSPan();
	// void addMember();
	void ft_print();

	class NumberFull : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
};
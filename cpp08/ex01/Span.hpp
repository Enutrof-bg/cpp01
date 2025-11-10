#pragma once

#include <iostream>
#include <string>

template <typename T> class Span
{
private:
	T val;
public:
	Span();
	Span(unsigned int n);
	~Span();
	Span(const Span &copy);
	Span &operator=(const Span &other);

	void addNumber();
	int shortestSpan();
	int longestSPan();
	void addMember();
};
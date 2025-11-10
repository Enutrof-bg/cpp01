#pragma once

#include <iostream>
#include <string>

class Span
{
private:

public:
	Span();
	Span(unsigned int n);
	~Span();
	Span(const Span &copy);
	Span &operator=(const Span &other);

	void addNumber();
};
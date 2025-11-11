#include "Span.hpp"


Span::Span()
{
}

Span::Span(unsigned int n): max(n), nbrVal(0)
{
	std::vector<int> v1(n);
}

Span::~Span()
{

}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &other)
{
	(void)other;
	// max = other.max;
	// nbrVal = other.nbrVal;
	return *this;
}

void Span::addNumber(int val)
{
	if (nbrVal >= max)
		throw Span::NumberFull();
	v1.push_back(val);
	nbrVal++;
}
void Span::ft_print()
{
	for (unsigned  i = 0; i < nbrVal; i++)
		std::cout << v1[i] << std::endl;
}

const char * Span::NumberFull::what() const throw()
{
	return ("Number full");
}
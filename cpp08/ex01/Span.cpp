#include "Span.hpp"

Span::Span(): max(0), nbrVal(0)
{
}

Span::Span(unsigned int n): max(n), nbrVal(0)
{
	// v1.reserve(n);
}

Span::~Span()
{
}

Span::Span(const Span &copy):max(copy.max), nbrVal(copy.nbrVal), v1(copy.v1)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		max = other.max;
		nbrVal = other.nbrVal;
		v1 = other.v1;
	}
	return *this;
}

void Span::addNumber(int val)
{
	if (nbrVal >= max)
		throw Span::NumberFull();
	v1.push_back(val);
	nbrVal++;
}

size_t Span::shortestSpan()
{
	if (nbrVal < 2)
		throw std::runtime_error("Span too small ;)");

	std::vector<int> cpy = v1;
	std::sort(cpy.begin(), cpy.end());
	size_t temp = std::numeric_limits<size_t>::max();

	std::vector<int>::iterator it = cpy.begin();
	std::vector<int>::iterator next = cpy.begin();
	next++;
	for (; next != cpy.end(); it++, next++)
	{
		size_t span = *next - *it;
		if (span < temp)
			temp = span;
	}
	return (temp);

}

size_t Span::longestSpan()
{
	if (nbrVal < 2)
		throw std::runtime_error("Span too small ;)");
		
	int min_val = *std::min_element(v1.begin(), v1.end());
    int max_val = *std::max_element(v1.begin(), v1.end());
    
    return static_cast<size_t>(max_val) - static_cast<size_t>(min_val);
}

void Span::addMember(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t count = std::distance(begin, end);
	if (count + nbrVal > max)
		throw Span::NumberFull();
	v1.insert(v1.end(), begin, end);
	nbrVal += count;
}

// void displayVal(int i)
// {
// 	std::cout << i << std::endl;
// }

void Span::ft_print()
{
	for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		std::cout << *it << std::endl;
	// for (unsigned  i = 0; i < nbrVal; i++)
		// std::cout << v1[i] << std::endl;
	// for_each(v1.begin(), v1.end(), displayVal);
}

const char * Span::NumberFull::what() const throw()
{
	return ("Number full");
}
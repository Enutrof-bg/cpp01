#include "iter.hpp"

template <typename T>
void ft_print(T &arg)
{
	std::cout << "P1" << std::endl;
	std::cout << arg << std::endl;
}

template <typename T>
void ft_print(T const & arg)
{
	std::cout << "P2" << std::endl;
	std::cout << arg << std::endl;
}

template <typename T>
void ft_double(T &arg)
{
	arg *= 2;
}

template <typename T>
void ft_double(const T &arg)
{
	arg *= 2;
}

template< typename T >
void print( T const & x )
{ 
	std::cout << "P3" << std::endl;
	std::cout << x << std::endl;
	return;
}


int main()
{
	std::cout << "TEST1"<<std::endl;
	int num[5] = {11,22,33,44,55};
	// iter(num, 5, ft_print);
	iter(num, 5, ft_double);
	std::cout << std::endl;
	// iter(num, 5, ft_print);


	std::cout << "\nTEST2"<<std::endl;
	const int num2[5] = {11,22,33,44,55};
	iter(num2, 5, ft_print);


	int tab[] = { 0, 1, 2, 3, 4 };
	iter( tab, 5, print);
}
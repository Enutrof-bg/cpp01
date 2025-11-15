#include "iter.hpp"

template <typename T>
void ft_print(T const & arg)
{
	std::cout << arg << std::endl;
}

template <typename T>
void ft_double(T const & arg)
{
	const_cast<T&>(arg) *= 2;
}

template< typename T >
void print( T const & x )
{ 
	std::cout << x << std::endl;
	return;
}


int main()
{
	std::cout << "TEST1"<<std::endl;
	int num[5] = {11,22,33,44,55};
	iter(num, 5, ft_print<int>);
	iter(num, 5, ft_double<int>);
	std::cout << std::endl;
	iter(num, 5, ft_print<int>);


	std::cout << "\nTEST2"<<std::endl;
	int num2[5] = {11,22,33,44,55};
	iter(num2, 5, print<int>);


	int tab[] = { 0, 1, 2, 3, 4 };
	iter( tab, 5, print<int>);
}
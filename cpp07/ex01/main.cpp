#include "iter.hpp"

template <typename T>
void ft_print(T const &arg)
{
	std::cout << arg << std::endl;
}

template< typename T >
void print( T & x )
{ 
	std::cout << x << std::endl;
	return;
}

template <typename T>
void ft_double(T &arg)
{
	(arg) *= 2;
}


template <typename T>
void ft_increment(T &arg)
{
    arg++;
}

template <typename T>
void ft_square(T &arg)
{
	arg = arg * arg;
}

template <typename T>
void ft_negate(T &arg)
{
	arg = -arg;
}

template <typename T>
void ft_divide_by_two(T &arg)
{
	arg /= 2;
}

int main()
{
	std::cout << "Test1"<<std::endl;
	int num[5] = {11,22,33,44,55};
	iter(num, 5, ft_print<int>);
	iter(num, 5, ft_double<int>);
	std::cout << std::endl;
	iter(num, 5, print<int>);


	std::cout << "\nTest2"<<std::endl;
	int num2[5] = {11,22,33,44,55};
	iter(num2, 5, print<int>);


	int tab[] = { 0, 1, 2, 3, 4 };
	iter( tab, 5, print<int>);

	{
		char chars[] = {'a', 'b', 'c', 'd'};
		iter(chars, 4, ft_print<char>);
		iter(chars, 4, ft_increment<char>);
		iter(chars, 4, ft_print<char>);
	}

	{
		const int cnums[] = {10, 20, 30};
    	iter(cnums, 3, ft_print<int>);
	}

	{
		std::string strs[] = {"hello", "world", "test"};
    	iter(strs, 3, ft_print<std::string>);
	}

	std::cout << "\nTest3"<<std::endl;
	{
		int nums[] = {1, 2, 3, 4, 5};
		std::cout << "Before: ";
		iter(nums, 5, ft_print<int>);
		iter(nums, 5, ft_square<int>);
		std::cout << "After square: ";
		iter(nums, 5, ft_print<int>);
	}

	std::cout << "\nTest4"<<std::endl;
	{
		double doubles[] = {1.5, -2.3, 4.7, -8.1};
		std::cout << "Before: ";
		iter(doubles, 4, ft_print<double>);
		iter(doubles, 4, ft_negate<double>);
		std::cout << "After negate: ";
		iter(doubles, 4, ft_print<double>);
	}

	std::cout << "\nTest5"<<std::endl;
	{
		float values[] = {10.0f, 20.0f, 30.0f, 40.0f};
		std::cout << "Before: ";
		iter(values, 4, ft_print<float>);
		iter(values, 4, ft_divide_by_two<float>);
		std::cout << "After divide: ";
		iter(values, 4, ft_print<float>);
	}

	std::cout << "\nTest6"<<std::endl;
	{
		int values[] = {5, 10, 15, 20};
		std::cout << "Original: ";
		iter(values, 4, ft_print<int>);
		
		iter(values, 4, ft_double<int>);
		std::cout << "After double: ";
		iter(values, 4, ft_print<int>);
		
		iter(values, 4, ft_increment<int>);
		std::cout << "After increment: ";
		iter(values, 4, ft_print<int>);
		
		iter(values, 4, ft_divide_by_two<int>);
		std::cout << "After divide by 2: ";
		iter(values, 4, ft_print<int>);
	}
}
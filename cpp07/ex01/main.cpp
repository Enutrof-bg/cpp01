#include "iter.hpp"

template <typename T>
void ft_print(T &arg)
{
	std::cout << arg << std::endl;
}

template <typename T>
void ft_print(const T &arg)
{
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

int main()
{
	std::cout << "TEST1"<<std::endl;
	int num[5] = {11,22,33,44,55};
	iter(num, 5, ft_print<int>);
	iter(num, 5, ft_double<int>);
	std::cout << std::endl;
	iter(num, 5, ft_print<int>);

	std::cout << "\nTEST2"<<std::endl;
	const int num2[5] = {11,22,33,44,55};
	iter(num2, 5, ft_print<int>);
}
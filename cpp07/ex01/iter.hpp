#pragma once

#include <iostream>
#include <string>

template <typename T>
void ft_print(T &arg)
{
	std::cout << arg << std::endl;
}

template <typename T>
void ft_double(T &arg)
{
	arg *= 2;
}

template <typename T> void iter(T *arr, const int len, void(*f)(T &))
{
	int i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}

template <typename T> void iter(T *arr, const int len, void(*f)(T const &))
{
	int i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}
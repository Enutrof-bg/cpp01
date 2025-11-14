#pragma once

#include <iostream>
#include <string>

template <typename T1, typename T2>
void iter(T1 *arr, std::size_t len, void(*f)(T2 const &f))
{
	std::cout <<"iter1" << std::endl;
	if (!arr || !f)
		return ;
	std::size_t i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}

// template <typename T, typename T2>
// void iter(T *arr, size_t len, void(*f)(T2 &))
// {
// 	if (!arr || !f)
// 		return ;
// 	size_t i = 0;
// 	while (i < len)
// 	{
// 		f(arr[i]);
// 		i++;
// 	}
// }

template <typename T>
void iter(T *arr, std::size_t len, void(*f)(const T &))
{
	std::cout <<"iter2" << std::endl;
	if (!arr || !f)
		return ;
	std::size_t i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}

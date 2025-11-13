#pragma once

#include <iostream>
#include <string>

template <typename T1, typename T2>
void iter(T1 *arr, size_t len, T2 f)
{
	if (!arr || !f)
		return ;
	size_t i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}

template <typename T, typename T2>
void iter(T *arr, size_t len, void(*f)(T2 &))
{
	if (!arr || !f)
		return ;
	int i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}

template <typename T>
void iter(T *arr, size_t len, void(*f)(T &))
{
	if (!arr || !f)
		return ;
	int i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}
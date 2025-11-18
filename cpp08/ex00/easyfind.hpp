#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>

template <typename T>
int easyfind(const T &container, int val)
{
	typename T::const_iterator it;

	it = std::find(container.begin(), container.end(), val);
	if (it == container.end())
		throw std::runtime_error("No occurrence found");
	return (std::distance(container.begin(), it));
}

// template <typename T>
// int easyfind(const T &container, int val)
// {
// 	int i = 0;
// 	while (container[i])
// 	{
// 		if (val == container[i])
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }


// typedef int caca;

// caca x = 10;


// template <typename S>
// void swap(S &x, S &y)
// {
// 	S temp;

// 	temp = x;
// 	x = y;
// 	y = temp;
// }

// template <typename T>
// const T& min(const T &x, const T &y)
// {
// 	if (x == y)
// 		return y;
// 	return (x > y ? y : x);
// }


// template <typename T>
// const T& max(const T &x, const T &y)
// {
// 	if (x == y)
// 		return y;
// 	return (x > y ? x : y);
// }
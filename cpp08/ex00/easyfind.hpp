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
// int easyfind(T container, int val)
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

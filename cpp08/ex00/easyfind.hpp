#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
int easyfind(T container, int val)
{
	int i = 0;
	while (container[i])
	{
		if (val == container[i])
			return (i);
		i++;
	}
	return (-1);
}

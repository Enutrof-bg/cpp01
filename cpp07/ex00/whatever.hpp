#pragma once

#include <iostream>
#include <string>

template <typename S> void swap(S &x, S &y)
{
	S temp;

	temp = x;
	x = y;
	y = temp;
}

template <typename T> const T& min(const T &x, const T &y)
{
	if (x == y)
		return y;
	return (x > y ? y : x);
}


template <typename T> const T& max(const T &x, const T &y)
{
	if (x == y)
		return y;
	return (x > y ? x : y);
}
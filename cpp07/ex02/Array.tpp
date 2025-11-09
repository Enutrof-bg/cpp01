#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	elements = new T[n];
	len = n;
}

template <typename T>
Array<T>::~Array()
{
}

template <typename T>
Array<T>::Array(const Array &copy)
{
	this = copy;
}

// template <typename T>
// Array<T>&operator=(const Array<T> &other)
// {

// }

	// Array &operator[]()


template <typename T>
unsigned int Array<T>::size()
{
	return len;
}
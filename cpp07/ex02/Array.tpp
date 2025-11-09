#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), len(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), len(n)
{
}

template <typename T>
Array<T>::~Array()
{
	delete[] elements;
}

template <typename T>
Array<T>::Array(const Array &copy): elements(NULL), len(0)
{
	*this = copy;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		len = other.len;
		delete[] elements;
		elements = NULL;
		if (len > 0)
		{
			elements = new T[len]();
			for (unsigned int i = 0; i < len; i++)
				elements[i] = other.elements[i];
		}
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= len)
		throw std::out_of_range("Array index out of range");
	return elements[index];
}


template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= len)
		throw std::out_of_range("Array index out of range");
	return elements[index];
}


template <typename T>
unsigned int Array<T>::size()
{
	return len;
}
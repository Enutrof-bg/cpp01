#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), len(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : elements(NULL), len(n)
{
	if (n > 0)
	{
		elements = new T[n]();
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] elements;
}

template <typename T>
Array<T>::Array(const Array &copy): elements(NULL), len(copy.len)
{
	if (len > 0)
	{
		elements = new T[len]();
		for (unsigned int i = 0; i < len; i++)
			elements[i] = copy.elements[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		T* temp = NULL;
		if (other.len > 0)
		{
			temp = new T[other.len]();
			for (unsigned int i = 0; i < other.len; i++)
				temp[i] = other.elements[i];
		}
		delete[] elements;
		elements = temp;
		len = other.len;
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
unsigned int Array<T>::size() const
{
	return len;
}
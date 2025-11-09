#pragma once

#include <iostream>
#include <string>

template <typename T>
class Array
{
private:
	T* elements;
	unsigned int len;
	
public:
	Array();
	Array(unsigned int n);
	~Array();
	Array(const Array &copy);
	// Array &operator=(const Array &other);

	// Array<T>&operator=(const Array<T> &other);
	
	Array &operator[]();

	unsigned int size();
};

#include "Array.tpp"
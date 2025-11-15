#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

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
	Array &operator=(const Array &other);

	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;

	unsigned int size() const;
};

#include "Array.tpp"
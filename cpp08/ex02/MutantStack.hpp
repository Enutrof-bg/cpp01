#pragma once

#include <iostream>
#include <string> 
#include <algorithm>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
private:

public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &copy);
	MutantStack &operator=(const MutantStack &other);

	typename MutantStack<T>::iterator MutantStack<T>::begin();
	typename MutantStack<T>::iterator MutantStack<T>::end();
};

#include "MutantStack.tpp"
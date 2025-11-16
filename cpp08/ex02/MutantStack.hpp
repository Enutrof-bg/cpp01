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

	typedef typename std::deque<T>::iterator iterator;

	// typename MutantStack<T>::iterator MutantStack<T>::begin();
	// typename MutantStack<T>::iterator MutantStack<T>::end();

	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"
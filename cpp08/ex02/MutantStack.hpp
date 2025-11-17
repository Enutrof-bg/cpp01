#pragma once

#include <iostream>
#include <string> 
#include <algorithm>
#include <stack>

// #include <vector>
// #include <list>
// #include <deque>
// #include <set>

// template <typename T>
// int easyfind(const T &container, int val)
// {
// 	typename T::const_iterator it;

// 	it = std::find(container.begin(), container.end(), val);
// 	if (it == container.end())
// 		throw std::runtime_error("No occurrence found");
// 	return (std::distance(container.begin(), it));
// }

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

	typename std::deque<T>::iterator begin();
	typename std::deque<T>::iterator end();
};

#include "MutantStack.tpp"
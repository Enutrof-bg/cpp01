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
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;
	

	typename std::deque<T>::iterator begin();
	typename std::deque<T>::iterator end();

	typename std::deque<T>::const_iterator begin() const;
	typename std::deque<T>::const_iterator end() const;

	typename std::deque<T>::reverse_iterator rbegin();
	typename std::deque<T>::reverse_iterator rend();

	typename std::deque<T>::const_reverse_iterator rbegin() const;
	typename std::deque<T>::const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"
#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{
	(void)copy;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	(void)other;
	return *this;
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename std::deque<T>::const_iterator MutantStack<T>::const_begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::const_end()
{
	return this->c.end();
}

template <typename T>
typename std::deque<T>::reverse_iterator MutantStack<T>::reverse_begin()
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::reverse_end()
{
	return this->c.rend();
}

template <typename T>
typename std::deque<T>::const_reverse_iterator MutantStack<T>::const_reverse_begin()
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::const_reverse_end()
{
	return this->c.rend();
}
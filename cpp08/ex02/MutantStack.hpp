#pragma once

#include <iostream>
#include <string> 
#include <algorithm>
#include <stack>

template<typename T>
class MutantStack
{
private:

public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &copy);
	MutantStack &operator=(const MutantStack &other);
};
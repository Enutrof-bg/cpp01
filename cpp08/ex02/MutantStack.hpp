#pragma once

#include <iostream>
#include <string> 
#include <algorithm>
#include <stack>

class MutantStack
{
private:

public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &copy);
	MutantStack &operator=(const MutantStack &other);
};
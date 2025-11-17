#pragma once 

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

class RPN
{
private:
	RPN();
	~RPN();
	RPN(const RPN &copy);
	RPN &operator=(const RPN &other);

public:
	static double calculate(char *argv);

};
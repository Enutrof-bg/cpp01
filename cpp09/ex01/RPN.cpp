#include "RPN.hpp"

RPN::RPN()
{}

RPN::~RPN()
{}

RPN::RPN(const RPN &copy)
{
	(void)copy;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

int isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int isOperat(char c)
{
	std::string operation = "+-*/";
	for(std::string::iterator it = operation.begin(); it != operation.end(); it++)
	{
		if (c == *it)
			return (0);
	}
	return (1);
}

double oper(const std::string &op, double a, double b)
{
	switch(op[0])
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: Division par 0");
			return (a / b);
		default :
			throw std::runtime_error("Error: Wrong operator");
	}
}

void push_pop(const std::string &temp, std::stack<double> &s)
{
	char *endptr;
	std::string operation = "+-*/";

	if (temp.size() == 1 
		&& operation.find(temp) != std::string::npos)
	{
		if (s.size() < 2)
			throw std::runtime_error("Error: stack size < 2 for operator");
		double a = s.top();
		s.pop();
		double b = s.top();
		s.pop();
		double res = oper(temp, b, a);
		s.push(res);
	}
	else if (temp.size() != 1 || isDigit(temp[0]) == 1)
		throw std::runtime_error("Value not a single digit");
	else
	{
		s.push(strtod(temp.c_str(), &endptr));
	}
}

void ft_check_str(std::string &str)
{
	std::string::iterator it;
	for (it = str.begin(); it != str.end(); it++)
	{
		if ((isDigit(*it) == 1 && isOperat(*it) == 1)&& (*it) != ' ')
			throw std::runtime_error("Error: non valid argument");
		if ((isDigit(*it) == 0 || isOperat(*it) == 0) && (*(it + 1) != ' ' && *(it+1) != '\0'))
			throw std::runtime_error("Error: non valid argument");
	}
	if (!(isDigit(str[str.size() - 1]) == 0 || isOperat(str[str.size() - 1]) == 0))
		throw std::runtime_error("Error: non valid argument");
}

double RPN::calculate(char *argv)
{
	std::stack<double> s;
	std::string str(argv);

	ft_check_str(str);
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	std::string::iterator it;
	for (it = str.begin(); it != str.end(); it++)
	{
		push_pop(std::string(1, *it), s);
	}
	if (s.size() != 1)
	{
		throw std::runtime_error("Error: stack not empty at end");
	}
	return (s.top());
}

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

double oper(std::string op, double a, double b)
{
	double res = -1.0;
	if (op == "+")
		res = a + b;
	else if (op == "-")
		res = a - b;
	else if (op == "*")
		res = a * b;
	else if (op == "/")
		res = a / b;
	// std::cout << "op:" << op << " a:"<< a<< " b:"<< b<<std::endl;
	// std::cout << "resHERE:" << res << std::endl;
	return res;
}

void push_pop(std::string temp, std::stack<double> &s)
{
	char *endptr;
	std::string operation = "+-*/";

	if (temp.size() == 1 
		&& operation.find(temp) != std::string::npos)
	{
		if (s.size() < 2)
			throw std::runtime_error("Error: stack size < 2 for operator");
		// std::cout << "operator:" <<temp << std::endl;
		double a = s.top();
		s.pop();
		double b = s.top();
		s.pop();

		double res = oper(temp, b, a);
		s.push(res);
		// std::cout << "res:" << res << std::endl;
	}
	else if (temp.size() != 1 || isDigit(temp[0]) == 1)
		throw std::runtime_error("Value not a single digit");
	else
	{
		s.push(strtod(temp.c_str(), &endptr));
		// std::cout <<"value:"<< temp << std::endl;
	}
}

double RPN::calculate(char *argv)
{
	std::stack<double> s;
	// char *endptr;
	// std::cout << "test:" << argv << std::endl;
	
	std::string str(argv);
	std::string limit = " ";
	std::string temp;
	// std::string operation = "+-*/";
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	// std::cout << str << std::endl;
	std::string::iterator it;
	for (it = str.begin(); it != str.end(); it++)
	{
		// std::cout << *it << std::endl;
		// std::string temp(it);
		push_pop(std::string(1, *it), s);
	}

	// std::cout << "size s:" << s.size() << std::endl;
	if (s.size() != 1)
		std::cout << "Error: Stack not empty" << std::endl;
	double res = s.top();
	return (res);
	// return (0);

}

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <string>
#include "iostream"
#include <ctime>
#include <cstdlib>

Base *generate(void)
{
	int random = rand();
	if (random % 3 == 0)
	{
		return new A;
	}
	else if (random % 3 == 1)
	{
		return new B;
	}
	else
		return new C;
}

void identify(Base* p)
{
	// A* derivedA = dynamic_cast<A*>(p);
	// B* derivedB = dynamic_cast<B*>(p);
	// C* derivedC = dynamic_cast<C*>(p);
	// if (derivedA != NULL)
	// 	std::cout << "A" << std::endl;
	// else if (derivedB != NULL)
	// 	std::cout << "B" << std::endl;
	// else if (derivedC != NULL)
	// 	std::cout << "C" << std::endl;

	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& derivedA = dynamic_cast<A&>(p);
		(void)derivedA;
		std::cout << "A" << std::endl;
	}
	catch(std::exception &e)
	{
		try
		{
			B& derivedB = dynamic_cast<B&>(p);
			(void)derivedB;
			std::cout << "B" << std::endl;
		}
		catch(std::exception &e)
		{
			try
			{
				C& derivedC = dynamic_cast<C&>(p);
				(void)derivedC;
				std::cout << "C" << std::endl;
			}	
			catch(std::exception &e)
			{
			}
		}

	}
}

int main()
{
	srand(time(0));
	Base *ptr = generate();

	std::cout << "identify *p:" << std::endl;
	identify(ptr);

	std::cout << "identify &p:" << std::endl;
	identify(*ptr);
	// (void)ptr;
}
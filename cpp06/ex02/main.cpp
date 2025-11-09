#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
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

int main()
{
	srand(time(0));
	Base *ptr = generate();
	(void)ptr;
}
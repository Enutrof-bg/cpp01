#include "Span.hpp"

int main()
{
	srand(time(0));
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(54);
		// sp.addNumber(54);
		// sp.addNumber(54);
		// sp.addNumber(54);
		// sp.ft_print();
		std::cout << "Shortest span: "<< sp.shortestSpan() << std::endl;
		std::cout << " Longest span: "<< sp.longestSpan() << std::endl;
		sp.ft_print();
	}
	catch(std::exception &e)
	{
		std::cout << "Erreur: " << e.what() << std::endl;
	}


	try
	{
		std::vector<int> big;
		for (int i = 0; i < 10000; i++)
		{
			big.push_back(rand());
		}
		// spbig.ft_print();

		Span gros = Span(20000);
		gros.addMember(big.begin(), big.end());
		gros.ft_print();
		std::cout << "Shortest span: "<< gros.shortestSpan() << std::endl;
		std::cout << " Longest span: "<< gros.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
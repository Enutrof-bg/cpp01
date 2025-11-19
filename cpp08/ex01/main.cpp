#include "Span.hpp"

int main()
{
	srand(time(0));
	std::cout << "Test1" << std::endl;
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

	std::cout << "\nTest2" << std::endl;
	try
	{
		Span gros = Span(20000);
		for (int i = 0; i < 10000; i++)
		{
			gros.addNumber(std::rand());
		}
		// gros.ft_print();

		std::cout << "Shortest span: "<< gros.shortestSpan() << std::endl;
		std::cout << " Longest span: "<< gros.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nTest3" << std::endl;
	try
	{
		std::vector<int> big;
		for (int i = 0; i < 10000; i++)
		{
			big.push_back(std::rand());
		}
		// spbig.ft_print();

		Span gros = Span(20000);
		gros.addMember(big.begin(), big.end());
		// gros.ft_print();

		std::cout << "Shortest span: "<< gros.shortestSpan() << std::endl;
		std::cout << " Longest span: "<< gros.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\nTest4" << std::endl;
	try
	{
		Span gros = Span(1000000);
		for (int i = 0; i < 100000; i++)
		{
			gros.addNumber(std::rand());
		}
		// gros.ft_print();

		std::cout << "Shortest span: "<< gros.shortestSpan() << std::endl;
		std::cout << " Longest span: "<< gros.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\nTest5" << std::endl;
	try
	{
		Span gros = Span(1000000);
		gros.addNumber(1);
		gros.addNumber(2);
		gros.addNumber(3);
		gros.addNumber(4);
		gros.addNumber(5);
		gros.ft_print();
		std::cout << "Shortest span: "<< gros.shortestSpan() << std::endl;
		std::cout << " Longest span: "<< gros.longestSpan() << std::endl;



		std::cout << "\nCopy:" << std::endl;
		Span newSpan = gros;
		newSpan.addNumber(99);
		newSpan.ft_print();
		std::cout << "Shortest new span: "<< newSpan.shortestSpan() << std::endl;
		std::cout << " Longest new span: "<< newSpan.longestSpan() << std::endl;



		std::cout << "\nAssignment:" << std::endl;
		Span newSpan2(gros);
		newSpan2.addNumber(7777);
		newSpan2.ft_print();
		std::cout << "Shortest new span: "<< newSpan2.shortestSpan() << std::endl;
		std::cout << " Longest new span: "<< newSpan2.longestSpan() << std::endl;

		std::cout << "\nOriginal:" << std::endl;
		gros.ft_print();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
#include "easyfind.hpp"

int main()
{
	std::cout << "Test1" << std::endl;
	std::vector<int> num;
	num.push_back(10);
	num.push_back(20);
	num.push_back(30);
	num.push_back(40);
	num.push_back(50);
	for (int i = 0; i < 5; i++)
		std::cout << num[i] << std::endl;
		
	try
	{
		std::cout << easyfind(num, 5) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << easyfind(num, 30) << std::endl;
		std::cout << "Found" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\nTest2" << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);
	 for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " " << std::endl;
	try
	{
		std::cout << easyfind(lst, 5) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << easyfind(lst, 30) << std::endl;
		std::cout << "Found" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\nTest3" << std::endl;
	std::deque<int> deque;
	deque.push_back(10);
	deque.push_back(20);
	deque.push_back(30);
	deque.push_back(40);
	deque.push_back(50);
	deque.push_front(30);
	for (int i = 0; i < 5; i++)
		std::cout << deque[i] << std::endl;
	try
	{
		std::cout << easyfind(deque, 5) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << easyfind(deque, 30) << std::endl;
		std::cout << "Found" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\nTest4" << std::endl;
	std::set<int> set;
	set.insert(10);
	set.insert(20);
	set.insert(30);
	set.insert(40);
	set.insert(50);
	set.insert(30);
	for (std::set<int>::iterator it = set.begin(); it != set.end(); it++)
		std::cout << *it << std::endl;
	try
	{
		std::cout << easyfind(set, 5) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << easyfind(set, 30) << std::endl;
		std::cout << "Found" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
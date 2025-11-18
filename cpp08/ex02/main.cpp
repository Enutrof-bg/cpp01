#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::cout << "Test1 sujet" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		// std::vector<int> s(mstack);
		// std::cout << "top: " << s.top() << std::endl;
	}

	std::cout << "\nTest2" << std::endl;
	{
		MutantStack<int> mstack;
	
		std::cout << "Initial empty: " << (mstack.empty() ? "true" : "false") << std::endl;
		std::cout << "Initial size: " << mstack.size() << std::endl;
		
		mstack.push(5);
		mstack.push(17);
		
		std::cout << "\nAfter push(5), push(17):" << std::endl;
		std::cout << "Top: " << mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
		
		mstack.pop();
		
		std::cout << "\nAfter pop():" << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
		std::cout << "Top: " << mstack.top() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		std::cout << "\nAfter push(3, 5, 737, 0):" << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;

	}

	std::cout << "\nTest3" << std::endl;
	{
		MutantStack<int> mstack;
		
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		mstack.push(6);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\nTest4" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		std::cout << "reverse:" << std::endl;
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();

		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
	}

	std::cout << "\nTest5" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(10);
		mstack.push(20);
		mstack.push(30);
		std::cout << "const:" << std::endl;
		MutantStack<int>::const_iterator cit = mstack.begin();
		MutantStack<int>::const_iterator cite = mstack.end();
		
		while (cit != cite)
		{
			std::cout << *cit << std::endl;
			++cit;
		}
	}

	std::cout << "\nTest6" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(100);
		mstack.push(200);
		mstack.push(300);
		
		std::cout << "const reverse:" << std::endl;
		MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
		MutantStack<int>::const_reverse_iterator crite = mstack.rend();
		
		while (crit != crite)
		{
			std::cout << *crit << std::endl;
			++crit;
		}
	}

	std::cout << "\nTest7" << std::endl;
	{
		MutantStack<int> original;
		original.push(1);
		original.push(2);
		original.push(3);
		
		MutantStack<int> copy(original);
		
		std::cout << "Original size: " << original.size() << std::endl;
		std::cout << "Copy size: " << copy.size() << std::endl;
		
		std::cout << "\nOriginal contents:" << std::endl;
		for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		
		std::cout << "\nCopy contents:" << std::endl;
		for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		
		// Modify copy
		copy.push(4);
		std::cout << "\nAfter push(4) to copy:" << std::endl;
		std::cout << "Original size: " << original.size() << std::endl;
		std::cout << "Copy size: " << copy.size() << std::endl;
	}

	std::cout << "\nTest8" << std::endl;
	{
		MutantStack<int> stack1;
		stack1.push(10);
		stack1.push(20);
		
		MutantStack<int> stack2;
		stack2.push(99);
		
		std::cout << "Before assignment:" << std::endl;
		std::cout << "Stack1 size: " << stack1.size() << ", top: " << stack1.top() << std::endl;
		std::cout << "Stack2 size: " << stack2.size() << ", top: " << stack2.top() << std::endl;
		
		stack2 = stack1;
		
		std::cout << "\nAfter stack2 = stack1:" << std::endl;
		std::cout << "Stack1 size: " << stack1.size() << ", top: " << stack1.top() << std::endl;
		std::cout << "Stack2 size: " << stack2.size() << ", top: " << stack2.top() << std::endl;
	}
	
	std::cout << "\nTest10" << std::endl;
	{
		MutantStack<int> mstack;
		std::list<int> mlist;
		
		mstack.push(5);
		mstack.push(17);
		
		mlist.push_back(5);
		mlist.push_back(17);
		
		std::cout << "MutantStack top: " << mstack.top() << std::endl;
		std::cout << "List back: " << mlist.back() << std::endl;
		
		mstack.pop();
		mlist.pop_back();
		
		std::cout << "\nAfter pop:" << std::endl;
		std::cout << "MutantStack size: " << mstack.size() << std::endl;
		std::cout << "List size: " << mlist.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);
		
		std::cout << "\nMutantStack contents:" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		
		std::cout << "\nList contents:" << std::endl;
		std::list<int>::iterator lit = mlist.begin();
		std::list<int>::iterator lite = mlist.end();
		while (lit != lite)
		{
			std::cout << *lit << std::endl;
			++lit;
		}
		}
		
		std::cout << "\nTest12" << std::endl;
	{
		MutantStack<std::string> strStack;
		
		strStack.push("Hello");
		strStack.push("World");
		strStack.push("MutantStack");
		strStack.push("Test");
		
		std::cout << "size: " << strStack.size() << std::endl;
		std::cout << "top: " << strStack.top() << std::endl;
		
		std::cout << "\nstrings:" << std::endl;
		for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it)
			std::cout << *it << std::endl;
	}
	
	std::cout << "\nTest13" << std::endl;
	{
		MutantStack<int> large;
		
		const int N = 10000;
		for (int i = 0; i < N; ++i)
			large.push(i);
		
		std::cout << "Pushed " << N << " elements" << std::endl;
		std::cout << "Size: " << large.size() << std::endl;
		std::cout << "Top: " << large.top() << std::endl;
		
		int count = 0;
		for (MutantStack<int>::iterator it = large.begin(); it != large.end(); ++it)
			count++;
	}
	return 0;
}
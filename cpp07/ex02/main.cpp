#include "Array.hpp"

template <typename T>
void ft_print(T &arg)
{
	for (unsigned int i = 0; i < arg.size(); i++)
	{
		std::cout << arg[i] << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "Test1" << std::endl;
	int *a = new int();
	std::cout << *a << std::endl;
	delete a;

	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		arr[i] = i;
	}
	ft_print(arr);

	std::cout << "\nTest2" << std::endl;
	Array<std::string> arrStr(3);
	arrStr[0] = "Hello";
	arrStr[1] = "Bonjour";
	arrStr[2] = "TEST";
	ft_print(arrStr);

	std::cout << "\nTest3" << std::endl;
	Array<int> newArr = arr;
	ft_print(newArr);
	newArr[0] = 42;

	ft_print(arr);
	ft_print(newArr);
	ft_print(arr);
	
	std::cout << "\nTest4" << std::endl;
	Array<int> newArr2(arr);
	newArr2[0] = 999;
	ft_print(newArr2);
	ft_print(arr);



	std::cout << "\nTest5" << std::endl;
	try {
		Array<int> a(10);
		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i;
		
		std::cout << "a.size() = " << a.size() << std::endl;
		
		Array<int> b(0);
		std::cout << "b.size() = " << b.size() << std::endl;
		
		a = b;
		
		std::cout << "Après a = b :" << std::endl;
		std::cout << "a.size() = " << a.size() << std::endl; 
		
		try {
			a[0] = 42;
			std::cerr << "Good" << std::endl;
			return 1;
		}
		catch (std::out_of_range &e) {
			std::cout << "Exception erreur: " << e.what() << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << "Erreur: " << e.what() << std::endl;
		return 1;
	}
		
	std::cout << "\nTest6" << std::endl;
	try {
		Array<int> a(5);
		Array<int> b(10);
		
		for (unsigned int i = 0; i < b.size(); i++)
			b[i] = i * 10;
		
		a = b;
		
		std::cout << "a.size() = " << a.size() << std::endl;
		std::cout << "a[5] = " << a[5] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception erreur: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
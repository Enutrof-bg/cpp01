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
	try
	{
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
	}	
	catch (std::exception &e)
	{
		std::cerr << "Exception erreur: " << e.what() << std::endl;
	}


	std::cout << "\nTest5" << std::endl;
	try
	{
	Array<double> doubles(4);
	doubles[0] = 3.14;
	doubles[1] = 2.71;
	doubles[2] = 1.41;
	doubles[3] = 1.73;
	ft_print(doubles);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception erreur: " << e.what() << std::endl;
	}

	std::cout << "\nTest5" << std::endl;
	try
	{
		Array<char> chars(5);
		chars[0] = 'H';
		chars[1] = 'e';
		chars[2] = 'l';
		chars[3] = 'l';
		chars[4] = 'o';
		ft_print(chars);
	}	
	catch (std::exception &e)
	{
		std::cerr << "Exception erreur: " << e.what() << std::endl;
	}

	std::cout << "\nTest6" << std::endl;
	try
	{
		Array<float> floats(3);
		floats[0] = 1.1f;
		floats[1] = 2.2f;
		floats[2] = 3.3f;

		Array<float> floatsCopy(floats);
		floatsCopy[0] = 99.9f;
		std::cout << "Original:" << std::endl;
		ft_print(floats);
		std::cout << "Copie:" << std::endl;
		ft_print(floatsCopy);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception erreur: " << e.what() << std::endl;
	}


	std::cout << "\nTest7" << std::endl;
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
		
	std::cout << "\nTest9" << std::endl;
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
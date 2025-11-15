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
	int *a = new(int);
	std::cout << *a << std::endl;
	delete a;

	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		// arr[i] = i;
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



	
	std::cout << " TEST 1: Bug operator= avec array vide " << std::endl;
	try {
		Array<int> a(10);
		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i;
		
		std::cout << "a.size() = " << a.size() << std::endl;
		
		Array<int> b(0);  // Array vide
		std::cout << "b.size() = " << b.size() << std::endl;
		
		a = b;  // Devrait mettre a.len à 0
		
		std::cout << "Après a = b :" << std::endl;
		std::cout << "a.size() = " << a.size() << std::endl;  // Devrait afficher 0
		
		if (a.size() != 0)
		{
			std::cerr << "a.size() devrait être 0 !" << std::endl;
			return 1;
		}
		
		std::cout << "a.size() == 0" << std::endl;
		
		// Test accès (devrait lever exception)
		try {
			a[0] = 42;
			std::cerr << "Devrait lever exception !" << std::endl;
			return 1;
		}
		catch (std::out_of_range &e) {
			std::cout << "Exception levée : " << e.what() << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << "Exception inattendue : " << e.what() << std::endl;
		return 1;
	}
		
	std::cout << "\n TEST 2: Assignation array non-vide " << std::endl;
	try {
		Array<int> a(5);
		Array<int> b(10);
		
		for (unsigned int i = 0; i < b.size(); i++)
			b[i] = i * 10;
		
		a = b;
		
		std::cout << "a.size() = " << a.size() << std::endl;  // Devrait être 10
		std::cout << "a[5] = " << a[5] << std::endl;  // Devrait être 50
		
		if (a.size() != 10 || a[5] != 50)
		{
			std::cerr << "BUG dans l'assignation" << std::endl;
			return 1;
		}
		
		std::cout << "Test OK" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception : " << e.what() << std::endl;
		return 1;
	}
		
	std::cout << "\n TEST 3: Exception-safety " << std::endl;
	try {
		Array<int> a(5);
		for (unsigned int i = 0; i < 5; i++)
			a[i] = i;
		
		// Simuler une grosse allocation (peut échouer)
		try {
			Array<int> huge(100000000000);  // 1 milliard d'int
			a = huge;
		}
		catch (std::bad_alloc &e) {
			std::cout << "bad_alloc attrapé (normal)" << std::endl;
			std::cout << "Vérifier que 'a' est toujours valide..." << std::endl;
			std::cout << "a.size() = " << a.size() << std::endl;  // Devrait être 5
			std::cout << "a[0] = " << a[0] << std::endl;  // Devrait être 0
			
			if (a.size() == 5 && a[0] == 0)
				std::cout << "Exception-safety OK : 'a' est intact" << std::endl;
			else
				std::cerr << "BUG : 'a' est corrompu" << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << "Exception : " << e.what() << std::endl;
		return 1;
	}
		
	std::cout << "\nTous les tests passent" << std::endl;
	return 0;
}
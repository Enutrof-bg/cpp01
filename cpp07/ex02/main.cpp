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
	std::cout << a << std::endl;
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
	return 0;
}
#include "Array.hpp"

template <typename T>
void ft_print(T &arg)
{
	for (unsigned int i = 0; i < arg.size(); i++)
	{
		std::cout << arg[i] << std::endl;
	}
}

int main()
{
	int *a = new(int);
	std::cout << a << std::endl;
	delete a;

	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		arr[i] = i * 10;
	}
	ft_print(arr);


	Array<std::string> arrStr(3);
	arrStr[0] = "Hello";
	arrStr[1] = "Bonjour";
	arrStr[2] = "TEST";
	ft_print(arrStr);


	Array<int> newArr = arr;
	ft_print(newArr);


	newArr[0] = 42;

	ft_print(arr);
	ft_print(newArr);
	
	return 0;
}
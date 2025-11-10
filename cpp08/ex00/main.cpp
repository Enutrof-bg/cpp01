#include "easyfind.hpp"

int main()
{
	std::vector<int> num;
	num.push_back(10);
	num.push_back(20);
	num.push_back(30);
	num.push_back(40);
	num.push_back(50);
	for (int i = 0; i < 5; i++)
		std::cout << num[i] << std::endl;
	std::cout << easyfind(num, 5) << std::endl;
	std::cout << easyfind(num, 30) << std::endl;


	// forward_list<int> arr;
	// arr.push_back(10);
	// arr.push_back(20);
	// arr.push_back(30);
	// arr.push_back(40);
	// arr.push_back(50);
}
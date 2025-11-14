#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	std::cout << "TEST1" << std::endl;
	Data *data = new Data();
	Data* after;
	uintptr_t tmp;
	data->age = 36;
	data->name = "bob";

	std::cout << data << std::endl;
	tmp = Serializer::serialize(data);
	std::cout << tmp << std::endl;
	after = Serializer::deserialize(tmp);
	std::cout << after << std::endl;

	if (data == after)
	{
		std::cout << "Identique" << std::endl;
	}
	else
	{
		std::cout << "Non Identique" << std::endl;
	}
	
	std::cout << "Before: " << std::endl;
	std::cout << "Name: "<<after->name << " Age: "<< after->age << std::endl;

	std::cout << "After: " << std::endl;
	data->name = "bobby";
	data->age = 24;
	std::cout << "Name: "<<after->name << " Age: "<< after->age << std::endl;
	delete data;


	std::cout << "\nTEST2" << std::endl;
	char str[18] = "Hello je suis bob";
	std::cout << str << std::endl;
	uintptr_t test = reinterpret_cast<uintptr_t>(str);
	std::cout << "uintptr_t test avant: " <<test << std::endl;
	test = test +5;
	std::cout << "uintptr_t test apres: " <<test << std::endl;
	char *newstr = reinterpret_cast<char *>(test);
	std::cout << newstr << std::endl;
	(void)str;


	std::cout << "\nTEST3" << std::endl;
	int x = 10;
	int *ptr = &x;

	std::cout << "ptr: " <<ptr << std::endl;
	double *d = reinterpret_cast<double *>(ptr);
	std::cout << "  d: " <<d << std::endl;
	
	std::cout << "ptr: " <<*ptr << std::endl;
	std::cout << "  d: " <<*d << std::endl; //undefined behavior

	
	return 0;
}
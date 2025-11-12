#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data *data = new Data();
	Data* after;
	uintptr_t tmp;
	data->age = 36;
	data->name = "bob";

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

	uintptr_t test = Serializer::serialize(data);
	Data *str = Serializer::deserialize(test);
	(void)str;

	delete data;


	
	return 0;
}
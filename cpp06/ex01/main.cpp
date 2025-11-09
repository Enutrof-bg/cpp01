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
	after = Serializer::deserialize(tmp);

	if (data == after)
	{
		std::cout << "Identique" << std::endl;
	}
	
	std::cout << after->name << std::endl;
	std::cout << after->age << std::endl;
	delete data;

	return 0;
}
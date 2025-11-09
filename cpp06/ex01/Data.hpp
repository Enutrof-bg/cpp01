#pragma once

#include <iostream>
#include <string>

class Data
{
private:
	
public:
	Data();
	~Data();
	Data(const Data &copy);
	Data &operator=(const Data &other);

	int age;
	std::string name;
};
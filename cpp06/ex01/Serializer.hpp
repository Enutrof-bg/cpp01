#pragma once

#include <stdint.h>
#include <iostream>
#include <string>
#include "Data.hpp"

class Serializer
{
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &other);

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
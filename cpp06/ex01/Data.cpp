#include "Data.hpp"

Data::Data()
{
}
Data::~Data()
{
}
Data::Data(const Data &copy)
{
	*this = copy;
}

Data &Data::operator=(const Data &other)
{
	(void)other;
	return *this;
}
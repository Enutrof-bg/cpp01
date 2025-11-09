#include "iter.hpp"



int main()
{
	int num[5] = {0, 32, 12, 65, 2};
	iter(num, 5, ft_print<int>);
	iter(num, 5, ft_double<int>);
	iter(num, 5, ft_print<int>);
}
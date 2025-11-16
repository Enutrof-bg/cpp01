#include "whatever.hpp"

int main()
{
	//test sujet
	std::cout << "Test1" << std::endl;
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	//int
	std::cout << "\nTest2" << std::endl;
	int i1 = 42, i2 = 21;
	std::cout << "Avant swap: i1=" << i1 << ", i2=" << i2 << std::endl;
	::swap(i1, i2);
	std::cout << "Après swap: i1=" << i1 << ", i2=" << i2 << std::endl;
	
	// double
	std::cout << "\nTest3" << std::endl;
	double d1 = 3.14, d2 = 2.71;
	std::cout << "Avant swap: d1=" << d1 << ", d2=" << d2 << std::endl;
	::swap(d1, d2);
	std::cout << "Après swap: d1=" << d1 << ", d2=" << d2 << std::endl;
	
	// char
	std::cout << "\nTest4" << std::endl;
	char c1 = 'A', c2 = 'Z';
	std::cout << "Avant swap: c1=" << c1 << ", c2=" << c2 << std::endl;
	::swap(c1, c2);
	std::cout << "Après swap: c1=" << c1 << ", c2=" << c2 << std::endl;


	std::cout << "\nTest5" << std::endl;
	{
		int a = -100;
		int b = -50;
		
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}

	std::cout << "\nTest6" << std::endl;
	{
		double a = 3.14159;
		double b = 2.71828;
		
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	} 

	std::cout << "\nTest7" << std::endl;
	{
		char a = 'z';
		char b = 'a';
		
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}
		
	std::cout << "\nTest8" << std::endl;
	{
		std::string a = "aaaaaaaaaaaaaaaaaaaa";
		std::string b = "zzzzzzzzzzzzzzzzzzzz";
		
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}
		

	
	std::cout << "\nTest9" << std::endl;
	{
		int int_max = 2147483647;
		int int_min = -2147483648;
		std::cout << "INT_MAX = " << int_max << std::endl;
		std::cout << "INT_MIN = " << int_min << std::endl;
		std::cout << "min(INT_MAX, INT_MIN) = " << ::min(int_max, int_min) << std::endl;
		std::cout << "max(INT_MAX, INT_MIN) = " << ::max(int_max, int_min) << std::endl;
	}
		
	std::cout << "\nTest10" << std::endl;
	{
		int a = 5;
		int b = 10;
		int c = 3;
		int d = 15;
		
		std::cout << "a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << std::endl;
		
		// min de min
		int result1 = ::min(::min(a, b), ::min(c, d));
		std::cout << "min(min(a,b), min(c,d)) = " << result1 << std::endl;
		
		// max de max
		int result2 = ::max(::max(a, b), ::max(c, d));
		std::cout << "max(max(a,b), max(c,d)) = " << result2 << std::endl;
	}

		
	std::cout << "\nTest11" << std::endl;
	{
		const int ca = 42;
		const int cb = 21;
		
		std::cout << "const a = " << ca << ", const b = " << cb << std::endl;
		
		const int& result_min = ::min(ca, cb);
		const int& result_max = ::max(ca, cb);
		
		std::cout << "min(const a, const b) = " << result_min << std::endl;
		std::cout << "max(const a, const b) = " << result_max << std::endl;
	}
		
	return 0;
}
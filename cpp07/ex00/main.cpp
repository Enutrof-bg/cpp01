#include "whatever.hpp"

int main()
{
	//test sujet
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
	int i1 = 42, i2 = 21;
	std::cout << "Avant swap: i1=" << i1 << ", i2=" << i2 << std::endl;
	::swap(i1, i2);
	std::cout << "Après swap: i1=" << i1 << ", i2=" << i2 << std::endl;
	
	// double
	double d1 = 3.14, d2 = 2.71;
	std::cout << "Avant swap: d1=" << d1 << ", d2=" << d2 << std::endl;
	::swap(d1, d2);
	std::cout << "Après swap: d1=" << d1 << ", d2=" << d2 << std::endl;
	
	// char
	char c1 = 'A', c2 = 'Z';
	std::cout << "Avant swap: c1=" << c1 << ", c2=" << c2 << std::endl;
	::swap(c1, c2);
	std::cout << "Après swap: c1=" << c1 << ", c2=" << c2 << std::endl;


{
	int a = -100;
	int b = -50;
	
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
}

{
        double a = 3.14159;
        double b = 2.71828;
        
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
        std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
} 

    {
        char a = 'z';
        char b = 'a';
        
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
        std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    }
    

    {
        std::string a = "aaaaaaaaaaaaaaaaaaaa";
        std::string b = "zzzzzzzzzzzzzzzzzzzz";
        
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
        std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
        
        // Vérifier qu'il n'y a pas de copie (performance)
        const std::string& result = ::min(a, b);
        if (&result == &a || &result == &b)
            std::cout << " Pas de copie (référence retournée)" << std::endl;
        else
            std::cout << " Copie détectée" << std::endl;
    }
    

    
   
    {
        // Valeurs maximales/minimales
        int int_max = 2147483647;
        int int_min = -2147483648;
        
        std::cout << "INT_MAX = " << int_max << std::endl;
        std::cout << "INT_MIN = " << int_min << std::endl;
        std::cout << "min(INT_MAX, INT_MIN) = " << ::min(int_max, int_min) << std::endl;
        std::cout << "max(INT_MAX, INT_MIN) = " << ::max(int_max, int_min) << std::endl;
        
        // Zéro
        int zero1 = 0;
        int zero2 = 0;
        std::cout << "\nmin(0, 0) = " << ::min(zero1, zero2) << std::endl;
        std::cout << "max(0, 0) = " << ::max(zero1, zero2) << std::endl;
    }
    
   
    {
        int a = 10;
        int b = 20;
        
        std::cout << "Avant: a=" << a << ", b=" << b << std::endl;
        
        // Modifier via la référence retournée par min
        int& min_ref = const_cast<int&>(::min(a, b));
        min_ref = 999;
        
        std::cout << "Après modification de min: a=" << a << ", b=" << b << std::endl;
        
        if (a == 999)
            std::cout << " min retourne bien une référence à a" << std::endl;
        else
            std::cout << " Problème avec le retour par référence" << std::endl;
    }
    
  
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
   
    {
        std::string empty1 = "";
        std::string empty2 = "";
        std::string str = "hello";
        
        std::cout << "empty1 = \"" << empty1 << "\"" << std::endl;
        std::cout << "empty2 = \"" << empty2 << "\"" << std::endl;
        std::cout << "str = \"" << str << "\"" << std::endl;
        
        std::cout << "min(empty1, empty2) = \"" << ::min(empty1, empty2) << "\"" << std::endl;
        std::cout << "min(empty1, str) = \"" << ::min(empty1, str) << "\"" << std::endl;
        std::cout << "max(empty1, str) = \"" << ::max(empty1, str) << "\"" << std::endl;
    }
    
    {
        // Créer une grosse string pour tester la performance
        std::string big1(10000, 'a');
        std::string big2(10000, 'b');
        
        std::cout << "Test avec strings de 10000 caractères..." << std::endl;
        
        const std::string& result = ::min(big1, big2);
        
        if (&result == &big1)
            std::cout << " Pas de copie : référence à big1 retournée" << std::endl;
        else if (&result == &big2)
            std::cout << " Pas de copie : référence à big2 retournée" << std::endl;
        else
            std::cout << " Copie détectée (mauvaise performance)" << std::endl;
        
        std::cout << "Taille du résultat: " << result.size() << std::endl;
    }
    
    
    {
        const int ca = 42;
        const int cb = 21;
        
        std::cout << "const a = " << ca << ", const b = " << cb << std::endl;
        
        // Doit compiler (min/max acceptent const)
        const int& result_min = ::min(ca, cb);
        const int& result_max = ::max(ca, cb);
        
        std::cout << "min(const a, const b) = " << result_min << std::endl;
        std::cout << "max(const a, const b) = " << result_max << std::endl;
    
    }
    
	return 0;
}
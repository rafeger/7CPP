#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << GREEN <<"a = " << a << ", b = " << b << DEFAULT <<std::endl;
	std::cout << GREEN <<"min(a, b) = " << ::min(a, b) << DEFAULT <<std::endl;
	std::cout << GREEN <<"max(a, b) = " << ::max(a, b) << DEFAULT <<std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << CYAN <<"c = " << c << ", d = " << d << DEFAULT <<std::endl;
	std::cout << CYAN <<"min(c, d) = " << ::min(c, d) << DEFAULT <<std::endl;
	std::cout << CYAN <<"max(c, d) = " << ::max(c, d) << DEFAULT <<std::endl;

	char e = '4';
	char f = '2';

	::swap(e, f);
	std::cout << YELLOW <<"e = " << e << ", f = " << f << DEFAULT <<std::endl;
	std::cout <<  YELLOW <<"min(e, f) = " << ::min(e, f) << DEFAULT <<std::endl;
	std::cout <<  YELLOW <<"max(e, f) = " << ::max(e, f) <<DEFAULT << std::endl;

	return (0);
}

#include "whatever.hpp"
#include <iostream>
#include <string>

int main()
{
	int a = 42;
	int b = 1337;

	std::cout << "int a = " << a << " | int b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min<int>(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max<int>(a, b) << std::endl;
	::swap<int>(a, b);
	std::cout << "swap(a, b) -> a = " << a << " | b = " << b << std::endl;

	float c = 42.42f;
	float d = 1337.42;
	std::cout << "float c = " << c << "f | float d = " << d << "f" << std::endl;
	std::cout << "min(c, d) = " << ::min<float>(c, d) << "f" << std::endl;
	std::cout << "max(c, d) = " << ::max<float>(c, d) << "f" << std::endl;
	::swap<float>(c, d);
	std::cout << "swap(c, d) -> c = " << c << "f | d = " << d << "f" << std::endl;

	double e = 42.42424242;
	double f = 1337.42424242;

	std::cout << "double e = " << e << " | double f = " << f << std::endl;
	std::cout << "min(e, f) = " << ::min<double>(e, f) << std::endl;
	std::cout << "max(e, f) = " << ::max<double>(e, f) << std::endl;
	::swap<double>(e, f);
	std::cout << "swap(e, f) -> e = " << e << " | f = " << f << std::endl;

	std::string g = "Thor1";
	std::string h = "Thor2";
	std::cout << "string g = " << g << " | string h = " << h << std::endl;
	std::cout << "min(g, h) = " << ::min<std::string>(g, h) << std::endl;
	std::cout << "max(g, h) = " << ::max<std::string>(g, h) << std::endl;
	::swap<std::string>(g, h);
	std::cout << "swap(g, h) -> string g = " << g << " | string h = " << h << std::endl;

	return 0;
}

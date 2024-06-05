#include "Fixed.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c;
	Fixed d(0.1f);
	Fixed e(0.2f);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << d * e << std::endl;
	std::cout << d / e << std::endl;
	try {
		std::cout << a / c << std::endl;
	} catch (std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

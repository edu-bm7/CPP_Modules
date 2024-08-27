#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void)
{
	std::vector< int > v;
	std::vector< int >::iterator it;
	std::vector< int >::iterator it_std;
	for (int i = 0; i < 11; i++) {
		v.push_back(95 + i);
	}

	for (int i = 0; i < 15; i++) {
		std::cout << i << ": ";
		it = easyfind(v, 95 + i);
		it_std = std::find(v.begin(), v.end(), 95 + i);
		std::cout << "[easyfind] ";
		if (it == v.end()) {
			std::cout << "Value not found";
		} else {
			std::cout << *it;
		}
		std::cout << " | ";
		if (it_std == v.end()) {
			std::cout << "Value not found";
		} else {
			std::cout << *it_std;
		}
		std::cout << " [std::find]" << std::endl;
	}
}

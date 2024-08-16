#include "RPN.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cerr << "Error: Usage: ./RPN notation";
		return 1;
	}

	try {
		RPN calc(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

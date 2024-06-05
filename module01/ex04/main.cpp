#include "replaceAll.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 4) {
		std::cerr << "Usage: filename str1 str2" << std::endl;
		return 1;
	}
	if (!replaceAll(argv[1], argv[2], argv[3])) {
		return 1;
	}
	return 0;
}

#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Usage: ./harlFilter Level" << std::endl;
		return 1;
	}
	Harl harl;
	
	switch(hashLevel(argv[1])) {
		case DEBUG:
			harl.complain("DEBUG");
		case INFO:
			harl.complain("INFO");
		case WARNING:
			harl.complain("WARNING");
		case ERROR:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
					  << std::endl;
			break;
	}
	return 0;
}

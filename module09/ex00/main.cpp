#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btc("data.csv");
		btc.printValues(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

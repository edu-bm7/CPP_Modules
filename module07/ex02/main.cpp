#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define MAX_VAL 750
int main(int, char**)
{

	{
		Array< int > numbers;
		std::cout << "Size of a empty Array: " << numbers.size() << std::endl;
	}

	{
		Array< int > numbers(42);
		std::cout << "Should be initialized to the default value (0): "
				  << numbers[0] << std::endl;
		numbers[0] = 3;
		std::cout << "Should be new value (3): " << numbers[0] << std::endl;
		std::cout << "Should fail:" << std::endl;
		try {
			numbers[42];
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		const Array< int > numbers(42);
		std::cout << "Testing const correctness (read-only): " << numbers[0] << std::endl;
		// Uncomment the line bellow to check the compile error with read-only instance.
		// numbers[0] = 3;
	}

	{
		Array< int > numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++) {
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array< int > tmp = numbers;
			Array< int > test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++) {
			if (mirror[i] != numbers[i]) {
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try {
			numbers[-2] = 0;
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		try {
			numbers[MAX_VAL] = 0;
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++) {
			numbers[i] = rand();
		}
		delete[] mirror;
	}

	{
		Array< std::string > name(4);
		int index;

		name[0] = "Peter";
		name[1] = "John";
		name[2] = "Jake";
		name[3] = "Matt";

		index = rand() % 3;

		std::cout << "Random name: " << name[index] << std::endl;
		std::cout << "Should be 4: " << name.size() << std::endl;

		std::cout << "Should fail:" << std::endl;
		try {
			std::cout << name[4] << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}

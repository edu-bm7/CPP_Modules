#include "iter.hpp"
#include <iostream>
#include <string>

template< typename T >
void printValues(T& i)
{
	std::cout << i << " ";
}

void incrementValues(int& i)
{
	i += 1;
}

int main()
{
	int arr[] = {4, 2, 3, 1, 5, 6};
	size_t arr_len = sizeof(arr) / sizeof(int);
	std::cout << "Int Array: " << std::endl;
	::iter< int >(arr, arr_len, printValues< const int >);
	std::cout << std::endl;

	std::cout << "Float Array: " << std::endl;
	float arr2[] = {4.2f, 2.2f, 3.2f, 1.2f, 5.2f, 6.2f};
	size_t arr2_len = sizeof(arr2) / sizeof(float);
	::iter< float >(arr2, arr2_len, printValues< float >);
	std::cout << std::endl;

	std::cout << "String Array: " << std::endl;
	std::string arr3[] = {"Abc", "Cde", "Fgh"};
	size_t arr3_len = sizeof(arr3) / sizeof(std::string);
	::iter< std::string >(arr3, arr3_len, printValues< std::string >);
	std::cout << std::endl;

	int arr4[] = {5, 6, 7, 8, 9};
	size_t arr4_len = sizeof(arr4) / sizeof(int);
	std::cout << "Int Array before increment: " << std::endl;
	::iter< int >(arr4, arr4_len, printValues< int >);
	std::cout << std::endl;
	::iter< int >(arr4, arr4_len, incrementValues);
	std::cout << "Int Array after increment: " << std::endl;
	::iter< int >(arr4, arr4_len, printValues< int >);
	std::cout << std::endl;

	return 0;
}

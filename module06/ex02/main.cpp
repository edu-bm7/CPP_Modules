#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <typeinfo>

// Functions to create the Classes
Base* createA()
{
	return new A;
}

Base* createB()
{
	return new B;
}

Base* createC()
{
	return new C;
}

// Pointer to functions that returns a Base* so we don't need if's and switch
// statements
typedef Base* (*CreateClass)();

Base* generate()
{
	CreateClass createClasses[] = {createA, createB, createC};

	int randomIndex = rand() % 3;

	return createClasses[randomIndex]();
}

// Functions to identify the type
std::string identifyA(Base* p)
{
	return dynamic_cast<A*>(p) ? "A" : "";
}

std::string identifyB(Base* p)
{
	return dynamic_cast<B*>(p) ? "B" : "";
}

std::string identifyC(Base* p)
{
	return dynamic_cast<C*>(p) ? "C" : "";
}

typedef std::string (*IdentifyClass)(Base*);

void identify(Base* p)
{
	const std::string classTypes[] = {"A", "B", "C"};
	IdentifyClass identifyClasses[] = {identifyA, identifyB, identifyC};
	size_t arr_length = sizeof(identifyClasses) / sizeof(IdentifyClass);

	for (size_t i = 0; i < arr_length; ++i) {
		if (identifyClasses[i](p) == classTypes[i]) {
			std::cout << "This is a " << classTypes[i] << " Class pointer."
					  << std::endl;
			return;
		}
	}

	std::cout << "This pointer can not be identified." << std::endl;
}

void identify(Base& p)
{
	try {
		A AClass = dynamic_cast<A&>(p);
		std::cout << "This is a A Class reference." << std::endl;
	} catch (const std::bad_cast& bc) {
		try {
			B BClass = dynamic_cast<B&>(p);
			std::cout << "This is a B Class reference." << std::endl;
		} catch (const std::bad_cast& bc) {
			try {
				C CClass = dynamic_cast<C&>(p);
				std::cout << "This is a C Class reference." << std::endl;
			} catch (const std::bad_cast& bc) {
				std::cout << "This reference can not be identified." << std::endl;
			}
		}
	}
}

int main()
{
	srand(time(0));

	Base* ptr1 = generate();
	Base* ptr2 = generate();

	if (!ptr1 || !ptr2) {
		return 1;
	}

	Base& ref1 = *ptr1;
	Base& ref2 = *ptr2;

	identify(ptr1);
	identify(ptr2);
	identify(ref1);
	identify(ref2);

	delete ptr1;
	delete ptr2;
	return 0;
}

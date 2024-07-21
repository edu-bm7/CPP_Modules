#include "Bureaucrat.hpp"

int main()
{
	try {
		std::cout << "\n-------------------------------------------------------\n"
				  << std::endl;
		Bureaucrat Eric("Eric", 0);
		std::cout << Eric << std::endl;
	} catch (std::exception& e) {
		std::cout << "Eric Error: " << e.what() << std::endl;
		std::cout << "\n-------------------------------------------------------\n"
				  << std::endl;
	}

	try {
		std::cout << "\n-------------------------------------------------------\n"
				  << std::endl;
		Bureaucrat Bob("Bob", 151);
		std::cout << Bob << std::endl;
	} catch (std::exception& e) {
		std::cout << "Bob Error: " << e.what() << std::endl;
		std::cout << "\n-------------------------------------------------------\n"
				  << std::endl;
	}

	try {
		Bureaucrat joe("Joe", 2);
		std::cout << "\n-------------------------------------------------------\n"
				  << std::endl;
		std::cout << "Before increment: " << joe << std::endl;
		joe.incrementGrade();
		std::cout << "After increment: " << joe << std::endl;
		joe.decrementGrade();
		std::cout << "After decrement: " << joe << std::endl;
		joe.incrementGrade();
		std::cout << "Before Error: " << joe << std::endl;
		joe.incrementGrade();
	} catch (std::exception& e) {
		std::cout << "Joe Error: " << e.what() << std::endl;
		std::cout << "\n-------------------------------------------------------\n"
				  << std::endl;
	}

	try {
		Bureaucrat max("Max", 149);
		std::cout << "\n-------------------------------------------------------\n"
				  << std::endl;
		Bureaucrat bar(max);
		std::cout << "\n-------------------------------------------------------\n"
				  << std::endl;
		Bureaucrat foo;
		std::cout << "\n-------------------------------------------------------\n"
				  << std::endl;
		foo = bar;
		std::cout << "\n-------------------------------------------------------\n"
				  << std::endl;
		std::cout << "Before increment: " << max << std::endl;
		max.incrementGrade();
		std::cout << "After increment: " << max << std::endl;
		max.decrementGrade();
		std::cout << "After decrement: " << max << std::endl;
		max.incrementGrade();
		std::cout << "After increment: " << max << std::endl;
		max.incrementGrade();
		std::cout << "After increment: " << max << std::endl;
		std::cout << "\n-------------------------------------------------------\n"
				  << std::endl;
		std::cout << "Before decrement: " << foo << std::endl;
		foo.decrementGrade();
		std::cout << "After decrement: " << foo << std::endl;
		foo.incrementGrade();
		std::cout << "After increment: " << foo << std::endl;
		std::cout << "\n-------------------------------------------------------\n"
				  << std::endl;
		std::cout << "Before decrement: " << bar << std::endl;
		bar.decrementGrade();
		std::cout << "Before Error: " << bar << std::endl;
		bar.decrementGrade();
	} catch (std::exception& e) {
		std::cout << "Bar('Max') Error: " << e.what() << std::endl;
		std::cout << "\n-------------------------------------------------------\n"
				  << std::endl;
	}
	return 0;
}

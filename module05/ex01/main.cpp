#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		try {
			std::cout << "\033[1m"
					  << "\033[94m"
					  << "\n--------------Parameterized Constructor [Valid Values Tests]---------------\n"
					  << "\033[0m" << std::endl;
			std::cout << "Bob: ";
			Form bob("bob", 149, 150);

			std::cout << "newBob: ";
			Form newBob(bob);

			std::cout << "Jimmy: ";
			Form jimmy("Jimmy", 2, 1);

			std::cout << "Chris: ";
			Form chris("Chris", 78, 42);
			std::cout << "\033[1m"
					  << "\033[94m"
					  << "\n---------------------Insertion operator [Overload Tests]----------------------\n"
					  << "\033[0m" << std::endl;
			std::cout << bob << std::endl;
			std::cout << newBob << std::endl;
			std::cout << jimmy << std::endl;
			std::cout << chris << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			std::cout << "\033[1m"
					  << "\033[94m"
					  << "\n---------------Parameterized Constructor [Invalid Values Tests]--------------\n"
					  << "\033[0m" << std::endl;
			std::cout << "Bob sign grade 0: ";
			Form bob("Bob", 0, 1);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "Jimmy sign grade 151: ";
			Form jimmy("Jimmy", 151, 150);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "Chris exec grade -42: ";
			Form chris("Chris", 5, -42);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "Harry exec grade 151: ";
			Form harry("Harry", 5, 151);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\033[1m"
				  << "\033[94m"
				  << "\n------------------signForm member function [Valid Values Tests]----------------\n"
				  << "\033[0m" << std::endl;
		try {
			Bureaucrat director("Director", 1);

			Form bob("bob", 1, 1);
			std::cout << bob << std::endl;
			director.signForm(bob);
			std::cout << "Bob after being signed by " << director << ":" << std::endl;
			std::cout << bob << std::endl;

			Form jimmy("jimmy", 150, 1);
			std::cout << jimmy << std::endl;
			director.signForm(jimmy);
			std::cout << "Jimmy after being signed by " << director << ":" << std::endl;
			std::cout << jimmy << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\033[1m"
				  << "\033[94m"
				  << "\n----------------signForm member function [Invalid Values Tests]----------------\n"
				  << "\033[0m" << std::endl;
		try {
			Bureaucrat sheriff("Sheriff", 2);
			Form bob("bob", 1, 1);
			std::cout << bob << std::endl;

			std::cout << "Signing Bob (sign grade 1) with Sheriff (grade 2): ";
			sheriff.signForm(bob);
			std::cout << bob << std::endl;

			Bureaucrat intern("Intern", 150);
			Form jimmy("jimmy", 149, 1);
			std::cout << jimmy << std::endl;

			std::cout << "Signing Jimmy (sign grade 149) with Intern (grade 150): ";
			intern.signForm(jimmy);
			std::cout << jimmy << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}

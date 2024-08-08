#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::srand(time(NULL));
	Intern john_doe;
	{
		try {
			std::cout << "\033[1m"
					  << "\033[94m"
					  << "\n--------------ShrubberyCreationForm [Valid Values Tests]---------------\n"
					  << "\033[0m" << std::endl;
			AForm* form1 = john_doe.makeForm("shrubbery creation", "home");
			Bureaucrat director("Director", 1);

			std::cout << *form1 << std::endl;
			director.signForm(*form1);
			std::cout << *form1 << std::endl;

			director.executeForm(*form1);
			std::cout << *form1 << std::endl;
			delete form1;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}


	{
		try {
			std::cout << "\033[1m"
					  << "\033[94m"
					  << "\n---------------RobotomyRequestForm [Valid Values Tests]--------------\n"
					  << "\033[0m" << std::endl;
			AForm* form1 = john_doe.makeForm("robotomy request", "David");
			Bureaucrat director("Director", 1);

			std::cout << *form1 << std::endl;
			director.signForm(*form1);
			std::cout << *form1 << std::endl;
			director.executeForm(*form1);
			director.executeForm(*form1);
			director.executeForm(*form1);
			director.executeForm(*form1);
			std::cout << *form1 << std::endl;
			delete form1;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}


	{
		std::cout << "\033[1m"
				  << "\033[94m"
				  << "\n------------------PresidentialPardonForm [Valid Values Tests]----------------\n"
				  << "\033[0m" << std::endl;
		try {
			AForm* form1 = john_doe.makeForm("presidential pardon", "Bob");
			Bureaucrat director("Director", 1);

			std::cout << *form1 << std::endl;
			director.signForm(*form1);
			std::cout << *form1 << std::endl;
			director.executeForm(*form1);
			std::cout << *form1 << std::endl;
			delete form1;

		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\033[1m"
				  << "\033[94m"
				  << "\n------------------Intern [Invalid Values Tests]----------------\n"
				  << "\033[0m" << std::endl;
		try {
			AForm* form1 = john_doe.makeForm("some invalid form", "Bob");
			Bureaucrat director("Director", 1);

			std::cout << *form1 << std::endl;
			director.signForm(*form1);
			std::cout << *form1 << std::endl;
			director.executeForm(*form1);
			std::cout << *form1 << std::endl;
			delete form1;

		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}

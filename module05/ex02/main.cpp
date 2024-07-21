#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::srand(time(NULL));
	{
		try {
			std::cout << "\033[1m"
					  << "\033[94m"
					  << "\n--------------ShrubberyCreationForm [Valid Values Tests]---------------\n"
					  << "\033[0m" << std::endl;
			ShrubberyCreationForm form1("home");
			Bureaucrat director("Director", 1);

			std::cout << form1 << std::endl;
			director.signForm(form1);
			std::cout << form1 << std::endl;

			director.executeForm(form1);
			std::cout << form1 << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		try {
			std::cout << "\033[1m"
					  << "\033[94m"
					  << "\n--------------ShrubberyCreationForm [Invalid Values Tests]---------------\n"
					  << "\033[0m" << std::endl;
			ShrubberyCreationForm form1("home");
			Bureaucrat sheriff("Sheriff", 138);

			std::cout << form1 << std::endl;
			sheriff.signForm(form1);
			std::cout << form1 << std::endl;

			sheriff.executeForm(form1);
			std::cout << form1 << std::endl;
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
			RobotomyRequestForm form1("Bob");
			Bureaucrat director("Director", 1);

			std::cout << form1 << std::endl;
			director.signForm(form1);
			std::cout << form1 << std::endl;
			director.executeForm(form1);
			director.executeForm(form1);
			director.executeForm(form1);
			director.executeForm(form1);
			std::cout << form1 << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		try {
			std::cout << "\033[1m"
					  << "\033[94m"
					  << "\n---------------RobotomyRequestForm [Invalid Values Tests]--------------\n"
					  << "\033[0m" << std::endl;
			RobotomyRequestForm form1("Bob");
			Bureaucrat sheriff("Sheriff", 46);

			std::cout << form1 << std::endl;
			sheriff.signForm(form1);
			std::cout << form1 << std::endl;
			sheriff.executeForm(form1);
			sheriff.executeForm(form1);
			sheriff.executeForm(form1);
			sheriff.executeForm(form1);
			std::cout << form1 << std::endl;
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
			PresidentialPardonForm form1("Bob");
			Bureaucrat director("Director", 1);

			std::cout << form1 << std::endl;
			director.signForm(form1);
			std::cout << form1 << std::endl;
			director.executeForm(form1);
			std::cout << form1 << std::endl;

		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\033[1m"
				  << "\033[94m"
				  << "\n------------------PresidentialPardonForm [Invalid Values Tests]----------------\n"
				  << "\033[0m" << std::endl;
		try {
			PresidentialPardonForm form1("Bob");
			Bureaucrat sheriff("Sheriff", 6);

			std::cout << form1 << std::endl;
			sheriff.signForm(form1);
			std::cout << form1 << std::endl;
			sheriff.executeForm(form1);
			std::cout << form1 << std::endl;

		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}

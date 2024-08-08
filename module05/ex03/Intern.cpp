#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Intern::Intern()
{
	std::cout << "Intern has been created with Default Constructor" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void) other;
	std::cout << "Intern has been created with Copy Constructor" << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

Intern& Intern::operator=(const Intern& rhs)
{
	(void) rhs;
	return *this;
}

/*-------------------------------EXCEPTIONS-----------------------------------*/

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Requested Form does not exist.";
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	InternMemFn arr[] = {
			&Intern::mMakeShrubberyCreationForm,
			&Intern::mMakeRobotomyRequestForm,
			&Intern::mMakePresidentialPardonForm};
	std::string names[] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"};
	const int namesCount = sizeof(arr) / sizeof(InternMemFn);

	// CALL_MEMBER_FN Macro expands to ((*this).*(arr[i]))
	for (int i = 0; i < namesCount; i++) {
		if (name == names[i]) {
			std::cout << "Intern creates " << name << ", the target is: "
					  << target << std::endl;
			return CALL_MEMBER_FN(*this, arr[i])(target);
		}
	}
	throw FormNotFoundException();
}

AForm* Intern::mMakeShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::mMakeRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::mMakePresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

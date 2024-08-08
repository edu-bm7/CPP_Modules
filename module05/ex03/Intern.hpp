#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

class Intern {
public:
	Intern();                    // Canonical Default Constructor
	Intern(const Intern& other); // Canonical Copy Constructor
	~Intern();                   // Canonical Default Destructor

	// Exception Nested Classes
	class FormNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	// Member Function
	AForm* makeForm(const std::string& name, const std::string& target);

	Intern& operator=(const Intern& rhs); // Canonical Assignment Operator
private:
	AForm* mMakeShrubberyCreationForm(const std::string& target);
	AForm* mMakeRobotomyRequestForm(const std::string& target);
	AForm* mMakePresidentialPardonForm(const std::string& target);
};

/*
 * How can I avoid syntax errors when creating pointers to members?
 * https://isocpp.org/wiki/faq/pointers-to-members#typedef-for-ptr-to-memfn
 * How can I avoid syntax errors when calling a member function 
 * using a pointer-to-member-function?
 * https://isocpp.org/wiki/faq/pointers-to-members#macro-for-ptr-to-memfn
 * How do I create and use an array of pointer-to-member-function?
 * https://isocpp.org/wiki/faq/pointers-to-members#array-memfnptrs
 *
 * How would it look like without typedef and macros for this simple usecase ?
 *
 * AForm* (Intern::*funcs[4])(const std::string&)
 * (this->*funcs[i])();
 *
 * We can see that it can get really messy and hard to read
 * */

typedef AForm* (Intern::*InternMemFn)(const std::string&);

#define CALL_MEMBER_FN(object, ptrToMember) ((object).*(ptrToMember))

#endif // INTERN_HPP

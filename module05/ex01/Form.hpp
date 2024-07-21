#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

// Forward declaration to resolve circular dependency
class Bureaucrat;

class Form {
public:
	Form();                  // Canonical Default Constructor
	Form(const Form& other); // Canonical Copy Constructor
	~Form();                 // Canonical Default Destructor
	Form(std::string name, const int sign, const int exec);

	Form& operator=(const Form& rhs); // Canonical Assignment Operator


	// Exception Nested Classes
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class UnassignableException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	// Getters
	const std::string& getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getIsSigned() const;

	// Member Functions
	void beSigned(const Bureaucrat& bureaucrat);

private:
	const std::string mName;
	const int mGradeToSign;
	const int mGradeToExecute;
	bool mIsSigned;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // FORM_HPP

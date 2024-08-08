#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

// Forward declaration to resolve circular dependency
class Bureaucrat;

class AForm {
public:
	AForm();                   // Canonical Default Constructor
	AForm(const AForm& other); // Canonical Copy Constructor
	virtual ~AForm();          // Canonical Default Destructor
	AForm(std::string name, const int sign, const int exec);

	AForm& operator=(const AForm& rhs); // Canonical Assignment Operator


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

	class UnsignedFormException : public std::exception {
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
	void execute(const Bureaucrat& executor) const;

protected:
	virtual void executeAction() const = 0;

private:
	const std::string mName;
	const int mGradeToSign;
	const int mGradeToExecute;
	bool mIsSigned;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif // FORM_HPP

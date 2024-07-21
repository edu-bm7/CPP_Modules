#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define MIN_GRADE 150
#define MAX_GRADE 1


// Forward declaration to resolve circular dependency
class AForm;

class Bureaucrat {
public:
	Bureaucrat();                        // Canonical Default Constructor
	Bureaucrat(const Bureaucrat& other); // Canonical Copy Constructor
	~Bureaucrat();                       // Canonical Default Destructor

	Bureaucrat(const std::string& name, int grade);

	Bureaucrat& operator=(const Bureaucrat& rhs); // Canonical Assignment Operator

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
	int getGrade() const;

	// Member Functions
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm& form);
	void executeForm(const AForm& form);

private:
	const std::string mName;
	int mGrade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_HPP

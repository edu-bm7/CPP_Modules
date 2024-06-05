#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
public:
	Bureaucrat();                        // Canonical Default Constructor
	Bureaucrat(Bureaucrat const& other); // Canonical Copy Constructor
	~Bureaucrat();                       // Canonical Default Destructor

	Bureaucrat(std::string const& name, int grade);

	Bureaucrat& operator=(Bureaucrat const& rhs); // Canonical Assignment Operator

	// Exception Nested Classes
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	// Getters
	std::string const& getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

private:
	std::string const mName;
	int mGrade;
	static int const smkMinGrade = 150;
	static int const smkMaxGrade = 1;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat);

#endif // BUREAUCRAT_HPP

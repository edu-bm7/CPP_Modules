#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

#define SCF_SIGN_GRADE 145
#define SCF_EXEC_GRADE 137

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();                                   // Canonical Default Constructor
	ShrubberyCreationForm(const ShrubberyCreationForm& other); // Canonical Copy Constructor
	virtual ~ShrubberyCreationForm();                          // Canonical Default Destructor
	ShrubberyCreationForm(std::string target);

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs); // Canonical Assignment Operator

	// Exception Nested Classes
	class FileCreateErrorException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class FileWriteErrorException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	// Getters
	std::string getTarget() const;

protected:
	virtual void executeAction() const;

private:
	std::string mTarget;
};

#endif // SHRUBBERYCREATIONFORM_HPP

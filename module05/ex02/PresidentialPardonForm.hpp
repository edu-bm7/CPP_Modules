#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

#define PPF_SIGN_GRADE 25
#define PPF_EXEC_GRADE 5

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();                                    // Canonical Default Constructor
	PresidentialPardonForm(const PresidentialPardonForm& other); // Canonical Copy Constructor
	virtual ~PresidentialPardonForm();                           // Canonical Default Destructor
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs); // Canonical Assignment Operator

	// Getters
	std::string getTarget() const;

protected:
	virtual void executeAction() const;

private:
	std::string mTarget;
};

#endif // PRESIDENTIALPARDONFORM_HPP

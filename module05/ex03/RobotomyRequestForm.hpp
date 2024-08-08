#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

#define RRF_SIGN_GRADE 72
#define RRF_EXEC_GRADE 45

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();                                 // Canonical Default Constructor
	RobotomyRequestForm(const RobotomyRequestForm& other); // Canonical Copy Constructor
	virtual ~RobotomyRequestForm();                        // Canonical Default Destructor
	RobotomyRequestForm(std::string target);

	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs); // Canonical Assignment Operator

	// Getters
	std::string getTarget() const;

protected:
	virtual void executeAction() const;

private:
	std::string mTarget;
};

#endif // ROBOTOMYREQUESTFORM_HPP

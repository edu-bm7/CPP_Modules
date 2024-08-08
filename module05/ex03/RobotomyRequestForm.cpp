#include "RobotomyRequestForm.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

RobotomyRequestForm::RobotomyRequestForm() : AForm(), mTarget("undefined")
{
	std::cout << "RobotomyRequestForm created with Default Constructor."
			  << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), mTarget(other.getTarget())
{
	std::cout << "RobotomyRequestForm created with Copy Constructor."
			  << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", RRF_SIGN_GRADE, RRF_EXEC_GRADE), mTarget(target)
{
	std::cout << "RobotomyRequestForm created with Parameterized Constructor."
			  << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called."
			  << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}
	return *this;
}
/*----------------------------MEMBER FUNCTIONS--------------------------------*/

void RobotomyRequestForm::executeAction() const
{
	std::cout << "Makes some drilling noises..." << std::endl;
	if (std::rand() % 2) {
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << getTarget() << " robotomy failed." << std::endl;
	}
}

/*---------------------------------GETTERS------------------------------------*/

std::string RobotomyRequestForm::getTarget() const
{
	return mTarget;
}

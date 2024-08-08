#include "PresidentialPardonForm.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

PresidentialPardonForm::PresidentialPardonForm() : AForm(), mTarget("undefined")
{
	std::cout << "PresidentialPardonForm created with Default Constructor."
			  << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), mTarget(other.getTarget())
{
	std::cout << "PresidentialPardonForm created with Copy Constructor."
			  << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", PPF_SIGN_GRADE, PPF_EXEC_GRADE), mTarget(target)
{
	std::cout << "PresidentialPardonForm created with Parameterized Constructor."
			  << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called."
			  << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}
	return *this;
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

void PresidentialPardonForm::executeAction() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox."
			  << std::endl;
}

/*---------------------------------GETTERS------------------------------------*/

std::string PresidentialPardonForm::getTarget() const
{
	return mTarget;
}

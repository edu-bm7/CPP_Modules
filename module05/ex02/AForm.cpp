#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

AForm::AForm() : mName("undefined_form"),
				 mGradeToSign(MIN_GRADE),
				 mGradeToExecute(MIN_GRADE),
				 mIsSigned(false)
{
	std::cout << "AForm " << mName
			  << " created with Default Constructor."
			  << " Sign grade: " << mGradeToSign
			  << " Execute Grade: " << mGradeToExecute
			  << std::endl;
}

AForm::AForm(const AForm& other) : mName(other.getName()),
								   mGradeToSign(other.getGradeToSign()),
								   mGradeToExecute(other.getGradeToExecute()),
								   mIsSigned(other.getIsSigned())
{
	std::cout << "AForm " << mName
			  << " created with Copy Constructor."
			  << " Sign grade: " << mGradeToSign
			  << " Execute Grade: " << mGradeToExecute
			  << std::endl;
}

AForm::AForm(std::string name, const int sign, const int exec) : mName(name),
																 mGradeToSign(sign),
																 mGradeToExecute(exec),
																 mIsSigned(false)
{
	if (mGradeToSign < MAX_GRADE || mGradeToExecute < MAX_GRADE) {
		throw GradeTooHighException();
	}
	if (mGradeToSign > MIN_GRADE || mGradeToExecute > MIN_GRADE) {
		throw GradeTooLowException();
	}
	std::cout << "AForm " << mName
			  << " created with Parameterized Constructor."
			  << " Sign grade: " << mGradeToSign
			  << " Execute Grade: " << mGradeToExecute
			  << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

AForm::~AForm()
{
	std::cout << "AForm " << mName
			  << " Destructor called." << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

AForm& AForm::operator=(const AForm& rhs)
{
	// Guard Self-Assignment
	if (this == &rhs) {
		std::cout << "AForm " << rhs.getName()
				  << " is the same as the Form " << mName
				  << std::endl;
		return *this;
	}
	throw UnassignableException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm Name: " << form.getName() << "\nIs Signed: "
	   << (form.getIsSigned() ? "Signed" : "Not signed")
	   << "\nGrade to be signed: " << form.getGradeToSign()
	   << "\nGrade to be executed: " << form.getGradeToExecute()
	   << std::endl;
	return os;
}

/*-------------------------------EXCEPTIONS-----------------------------------*/

const char* AForm::GradeTooHighException::what() const throw()
{
	return "The Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "The Grade is too low.";
}

const char* AForm::UnassignableException::what() const throw()
{
	return "Forms are unassignable.";
}

const char* AForm::UnsignedFormException::what() const throw()
{
	return "Form isn't signed.";
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > mGradeToSign) {
		throw GradeTooLowException();
	}
	mIsSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!mIsSigned) {
		throw AForm::UnsignedFormException();
	}
	if (executor.getGrade() > mGradeToExecute) {
		throw AForm::GradeTooLowException();
	}
	executeAction();
}

/*---------------------------------GETTERS------------------------------------*/

const std::string& AForm::getName() const
{
	return mName;
}

int AForm::getGradeToSign() const
{
	return mGradeToSign;
}

int AForm::getGradeToExecute() const
{
	return mGradeToExecute;
}

bool AForm::getIsSigned() const
{
	return mIsSigned;
}

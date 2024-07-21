#include "Form.hpp"
#include "Bureaucrat.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Form::Form() : mName("undefined_form"),
			   mGradeToSign(MIN_GRADE),
			   mGradeToExecute(MIN_GRADE),
			   mIsSigned(false)
{
	std::cout << "Form " << mName
			  << " created with Default Constructor."
			  << " Sign grade: " << mGradeToSign
			  << " Execute Grade: " << mGradeToExecute
			  << std::endl;
}

Form::Form(const Form& other) : mName(other.getName()),
								mGradeToSign(other.getGradeToSign()),
								mGradeToExecute(other.getGradeToExecute()),
								mIsSigned(other.getIsSigned())
{
	std::cout << "Form " << mName
			  << " created with Copy Constructor."
			  << " Sign grade: " << mGradeToSign
			  << " Execute Grade: " << mGradeToExecute
			  << std::endl;
}

Form::Form(std::string name, const int sign, const int exec) : mName(name),
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
	std::cout << "Form " << mName
			  << " created with Parameterized Constructor."
			  << " Sign grade: " << mGradeToSign
			  << " Execute Grade: " << mGradeToExecute
			  << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

Form::~Form()
{
	std::cout << "Form " << mName
			  << " Destructor called." << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

Form& Form::operator=(const Form& rhs)
{
	// Guard Self-Assignment
	if (this == &rhs) {
		std::cout << "Form " << rhs.getName()
				  << " is the same as the Form " << mName
				  << std::endl;
		return *this;
	}
	throw UnassignableException();
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form Name: " << form.getName() << "\nIs Signed: "
	   << (form.getIsSigned() ? "Signed" : "Not signed")
	   << "\nGrade to be signed: " << form.getGradeToSign()
	   << "\nGrade to be executed: " << form.getGradeToExecute()
	   << std::endl;
	return os;
}

/*-------------------------------EXCEPTIONS-----------------------------------*/

const char* Form::GradeTooHighException::what() const throw()
{
	return "The Grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "The Grade is too low.";
}

const char* Form::UnassignableException::what() const throw()
{
	return "Forms are unassignable.";
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > mGradeToSign) {
		throw GradeTooLowException();
	}
	mIsSigned = true;
}

/*---------------------------------GETTERS------------------------------------*/

const std::string& Form::getName() const
{
	return mName;
}

int Form::getGradeToSign() const
{
	return mGradeToSign;
}

int Form::getGradeToExecute() const
{
	return mGradeToExecute;
}

bool Form::getIsSigned() const
{
	return mIsSigned;
}

#include "Bureaucrat.hpp"
#include "AForm.hpp"
/*-------------------------------CONSTRUCTORS---------------------------------*/

Bureaucrat::Bureaucrat() : mName("undefined"), mGrade(MIN_GRADE)
{
	std::cout << "Bureaucrat " << mName
			  << " created with Default Constructor." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : mName(other.getName()),
												  mGrade(other.getGrade())
{
	std::cout << "Bureaucrat " << mName
			  << " created with Copy Constructor." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : mName(name),
															 mGrade(grade)
{
	if (mGrade < MAX_GRADE) {
		throw GradeTooHighException();
	}
	if (mGrade > MIN_GRADE) {
		throw GradeTooLowException();
	}
	std::cout << "Bureaucrat " << mName
			  << " created with Parameterized Constructor." << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << mName
			  << " Destructor called." << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	// Guard Self-Assignment
	if (this == &rhs) {
		std::cout << "Bureaucrat " << rhs.getName()
				  << " is the same as the Bureaucrat " << mName
				  << std::endl;
		return *this;
	}
	throw Bureaucrat::UnassignableException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", a Bureaucrat Grade "
	   << bureaucrat.getGrade();
	return os;
}

/*-------------------------------EXCEPTIONS-----------------------------------*/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat's grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat's grade is too low!";
}


const char* Bureaucrat::UnassignableException::what() const throw()
{
	return "Bureaucrats are unassignable.";
}
/*----------------------------MEMBER FUNCTIONS--------------------------------*/

const std::string& Bureaucrat::getName() const
{
	return mName;
}

int Bureaucrat::getGrade() const
{
	return mGrade;
}

void Bureaucrat::incrementGrade()
{
	if (mGrade <= MAX_GRADE) {
		throw GradeTooHighException();
	}
	mGrade--;
}

void Bureaucrat::decrementGrade()
{
	if (mGrade >= MIN_GRADE) {
		throw GradeTooLowException();
	}
	mGrade++;
}

void Bureaucrat::signForm(AForm& form)
{
	try {
		form.beSigned(*this);
		std::cout << mName << " signed form " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << mName << ", grade " << mGrade << " couldn't sign form "
				  << form.getName() << " because: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form)
{
	try {
		form.execute(*this);
		std::cout << mName << " executed form " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << mName << ", grade " << mGrade << " couldn't execute form "
				  << form.getName() << " because: " << e.what() << std::endl;
	}
}

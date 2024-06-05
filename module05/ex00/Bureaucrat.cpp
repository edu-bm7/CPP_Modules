#include "Bureaucrat.hpp"
#include <iostream>

/*-------------------------------CONSTRUCTORS---------------------------------*/

Bureaucrat::Bureaucrat() : mName("undefined"), mGrade(smkMinGrade)
{
	std::cout << "Bureaucrat " << mName
			  << " created with Default Constructor." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& other) : mName(other.getName()),
												  mGrade(other.getGrade())
{
	std::cout << "Bureaucrat " << mName
			  << " created with Copy Constructor." << std::endl;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : mName(name),
															 mGrade(grade)
{
	if (mGrade < smkMaxGrade) {
		throw GradeTooHighException();
	}
	if (mGrade > smkMinGrade) {
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

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs)
{

	std::cout << "Bureaucrat " << rhs.getName()
			  << " grade has been assigned to Bureaucrat " << mName
			  << " grade." << std::endl;
	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}
	mGrade = rhs.getGrade();
	return *this;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade "
	   << bureaucrat.getGrade() << ".";
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

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

std::string const& Bureaucrat::getName() const
{
	return mName;
}

int Bureaucrat::getGrade() const
{
	return mGrade;
}

void Bureaucrat::incrementGrade()
{
	if (mGrade <= smkMaxGrade) {
		throw GradeTooHighException();
	}
	mGrade--;
}

void Bureaucrat::decrementGrade()
{
	if (mGrade >= smkMinGrade) {
		throw GradeTooLowException();
	}
	mGrade++;
}

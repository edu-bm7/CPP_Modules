#include "WrongAnimal.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

WrongAnimal::WrongAnimal() : mType("WrongAnimal")
{
	std::cout << "WrongAnimal's Default Constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& other) : mType(other.getType())
{
	std::cout << "WrongAnimal's Copy constructor called." << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal's Destructor called." << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& rhs)
{
	std::cout << "WrongAnimal's Assignment Operator called." << std::endl;

	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}

	mType = rhs.getType();

	return *this;
}

/*---------------------------------METHODS------------------------------------*/

void WrongAnimal::makeSound() const
{
	std::cout << "~BOING!~" << std::endl;
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

std::string WrongAnimal::getType() const
{
	return mType;
}

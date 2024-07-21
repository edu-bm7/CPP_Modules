#include "Animal.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Animal::Animal() : mType("Animal")
{
	std::cout << "Animal's Default Constructor called." << std::endl;
}

Animal::Animal(Animal const& other) : mType(other.getType())
{
	std::cout << "Animal's Copy constructor called." << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

Animal::~Animal()
{
	std::cout << "Animal's Destructor called." << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

Animal& Animal::operator=(Animal const& rhs)
{
	std::cout << "Animal's Assignment Operator called." << std::endl;

	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}

	mType = rhs.getType();

	return *this;
}

/*---------------------------------METHODS------------------------------------*/

void Animal::makeSound() const
{
	std::cout << "~GRRRRRRRRRRRRRRRRRRRRRRRRRRRR~" << std::endl;
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

std::string Animal::getType() const
{
	return mType;
}

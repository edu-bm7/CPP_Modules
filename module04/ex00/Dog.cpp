#include "Dog.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Dog::Dog() : Animal()
{
	mType = "Dog";
	std::cout << "Dog's Default Constructor called." << std::endl;
}

Dog::Dog(Dog const& other) : Animal(other)
{
	mType = other.getType();
	std::cout << "Dog's Copy constructor called." << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

Dog::~Dog()
{
	std::cout << "Dog's Destructor called." << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

Dog& Dog::operator=(Dog const& rhs)
{
	std::cout << "Dog's Assignment Operator called." << std::endl;

	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}

	mType = rhs.getType();

	return *this;
}

/*---------------------------------METHODS------------------------------------*/

void Dog::makeSound() const
{
	std::cout << "~grrr woof woof~" << std::endl;
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

std::string Dog::getType() const
{
	return mType;
}

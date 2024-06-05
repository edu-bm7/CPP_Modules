#include "WrongCat.hpp"
#include <iostream>

/*-------------------------------CONSTRUCTORS---------------------------------*/

WrongCat::WrongCat() : WrongAnimal()
{
	mType = "WrongCat";
	std::cout << "WrongCat's Default Constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const& other) : WrongAnimal(other)
{
	mType = other.getType();
	std::cout << "WrongCat's Copy constructor called." << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

WrongCat::~WrongCat()
{
	std::cout << "WrongCat's Destructor called." << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

WrongCat& WrongCat::operator=(WrongCat const& rhs)
{
	std::cout << "WrongCat's Assignment Operator called." << std::endl;

	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}

	mType = rhs.getType();

	return *this;
}

/*---------------------------------METHODS------------------------------------*/

void WrongCat::makeSound() const
{
	std::cout << "~prrrrr Mmmmgrrgrgiauuuurrrr~" << std::endl;
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

std::string WrongCat::getType() const
{
	return mType;
}

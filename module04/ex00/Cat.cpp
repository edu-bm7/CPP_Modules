#include "Cat.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Cat::Cat() : Animal()
{
	mType = "Cat";
	std::cout << "Cat's Default Constructor called." << std::endl;
}

Cat::Cat(Cat const& other) : Animal(other)
{
	mType = other.getType();
	std::cout << "Cat's Copy constructor called." << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

Cat::~Cat()
{
	std::cout << "Cat's Destructor called." << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

Cat& Cat::operator=(Cat const& rhs)
{
	std::cout << "Cat's Assignment Operator called." << std::endl;

	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}

	mType = rhs.getType();

	return *this;
}

/*---------------------------------METHODS------------------------------------*/

void Cat::makeSound() const
{
	std::cout << "~prrrr prrrr miiau~" << std::endl;
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

std::string Cat::getType() const
{
	return mType;
}

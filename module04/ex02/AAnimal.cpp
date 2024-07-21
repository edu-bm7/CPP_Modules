#include "AAnimal.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

AAnimal::AAnimal() : mType("Animal")
{
	std::cout << "Abstract Animal's Default Constructor called." << std::endl;
}

AAnimal::AAnimal(AAnimal const& other) : mType(other.getType())
{
	std::cout << "Abstract Animal's Copy constructor called." << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

AAnimal::~AAnimal()
{
	std::cout << "Abstract Animal's Destructor called." << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

AAnimal& AAnimal::operator=(AAnimal const& rhs)
{
	std::cout << "Abstract Animal's Assignment Operator called." << std::endl;

	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}

	mType = rhs.getType();

	return *this;
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

std::string AAnimal::getType() const
{
	return mType;
}

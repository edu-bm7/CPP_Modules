#include "Cat.hpp"
#include <iostream>

/*-------------------------------CONSTRUCTORS---------------------------------*/

Cat::Cat() : AAnimal()
{
	mType = "Cat";
	try {
		mBrain = new Brain();
		std::cout << "Cat's Default Constructor called." << std::endl;
	} catch (std::bad_alloc& e) {
		std::cerr << "Cat's Brain Memory allocation failure" << std::endl;
		mBrain = NULL;
	}
}

Cat::Cat(Cat const& other) : AAnimal(other), mBrain(NULL)
{
	std::cout << "Cat's Copy constructor called." << std::endl;

	mType = other.getType();

	// Only creates Brain if OTHER's Brain isn't NULL
	if (other.getBrain()) {
		try {
			mBrain = new Brain(*other.getBrain());
		} catch (std::bad_alloc& e) {
			std::cerr << "Cat's Brain Copy Memory allocation failure"
					  << std::endl;
			mBrain = NULL;
		}
	} else {
		std::cerr << "OTHER Cat's Brain is NULL!" << std::endl;
	}
}

/*--------------------------------DESTRUCTOR----------------------------------*/

Cat::~Cat()
{
	if (mBrain) {
		std::cout << "Cat Brain Address before deletion: " << mBrain
				  << std::endl;
		delete mBrain;
		mBrain = NULL;
		std::cout << "Cat's Brain deleted! Brain Value: " << mBrain << std::endl;
	}
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

	// Only deletes Brain if this->mBrain isn't NULL
	if (mBrain) {
		delete mBrain;
		mBrain = NULL;
	}

	// Only creates a new Brain if RHS Brains isn't NULL
	if (rhs.getBrain()) {
		try {
			mBrain = new Brain(*rhs.getBrain());
		} catch (std::bad_alloc& e) {
			std::cerr << "Cat's Brain Assign Operator memory failure: " << e.what()
					  << std::endl;
			mBrain = NULL;
		}
	} else {
		std::cerr << "RHS Cat's Brain is NULL!" << std::endl;
	}

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

Brain* Cat::getBrain() const
{
	return mBrain;
}

#include "Dog.hpp"
#include <iostream>

/*-------------------------------CONSTRUCTORS---------------------------------*/

Dog::Dog() : Animal()
{
	mType = "Dog";
	try {
		mBrain = new Brain();
		std::cout << "Dog's Default Constructor called." << std::endl;
	} catch (std::bad_alloc& e) {
		std::cerr << "Dog's Brain memory allocation failure: " << e.what()
				  << std::endl;
		mBrain = NULL;
	}
}

Dog::Dog(Dog const& other) : Animal(other), mBrain(NULL)
{
	std::cout << "Dog's Copy constructor called." << std::endl;

	mType = other.getType();

	// Only creates Brain if OTHER's Brain isn't NULL
	if (other.getBrain()) {
		try {
			mBrain = new Brain(*other.getBrain());
		} catch (std::bad_alloc& e) {
			std::cerr << "Dog's Brain Copy memory allocation failure: " << e.what()
					  << std::endl;
			mBrain = NULL;
		}
	} else {
		std::cerr << "OTHER Dog's Brain is NULL!" << std::endl;
	}
}

/*--------------------------------DESTRUCTOR----------------------------------*/

Dog::~Dog()
{
	if (mBrain) {
		std::cout << "Dog Brain Address before deletion: " << mBrain
				  << std::endl;
		delete mBrain;
		mBrain = NULL;
		std::cout << "Dog's Brain deleted! Brain Value: " << mBrain
				  << std::endl;
	}
	std::cout << "Dog's Destructor called." << std::endl;
}

/*--------------------------------OVERLOAD------------------------------------*/

Dog& Dog::operator=(Dog const& rhs)
{
	std::cout << "Dog's Assignment Operator called." << std::endl;

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
			std::cerr << "Dog's Brain Assign Operator memory failure: " << e.what()
					  << std::endl;
			mBrain = NULL;
		}
	} else {
		std::cerr << "RHS Dog's Brain is NULL!" << std::endl;
	}

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

Brain* Dog::getBrain() const
{
	return mBrain;
}

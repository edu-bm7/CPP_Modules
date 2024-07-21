#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public AAnimal {
public:
	Dog();                 // Canonical Default Constructor
	Dog(Dog const& other); // Canonical Copy Constructor
	~Dog();                // Canonical Default Destructor

	Dog& operator=(Dog const& rhs); // Canonical Assignment Operator

	virtual void makeSound() const;
	std::string getType() const;
	Brain* getBrain() const;

private:
	Brain* mBrain;
};

#endif // DOG_HPP

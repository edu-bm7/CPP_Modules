#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {
public:
	Dog();                 // Canonical Default Constructor
	Dog(Dog const& other); // Canonical Copy Constructor
	~Dog();                // Canonical Default Destructor

	Dog& operator=(Dog const& rhs); // Canonical Assignment Operator

	virtual void makeSound() const;
	std::string getType() const;
};

#endif // DOG_HPP

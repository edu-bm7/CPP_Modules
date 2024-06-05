#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:
	Animal();                    // Canonical Default Constructor
	Animal(Animal const& other); // Canonical Copy Constructor
	virtual ~Animal();           // Canonical Default Destructor

	Animal& operator=(Animal const& rhs); // Canonical Assignment Operator

	virtual void makeSound() const;
	std::string getType() const;

protected:
	std::string mType;
};

#endif // ANIMAL_HPP

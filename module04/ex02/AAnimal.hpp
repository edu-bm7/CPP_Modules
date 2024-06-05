#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class AAnimal {
public:
	AAnimal();                     // Canonical Default Constructor
	AAnimal(AAnimal const& other); // Canonical Copy Constructor
	virtual ~AAnimal();            // Canonical Default Destructor

	AAnimal& operator=(AAnimal const& rhs); // Canonical Assignment Operator

	virtual void makeSound() const = 0;
	std::string getType() const;

protected:
	std::string mType;
};

#endif // ANIMAL_HPP

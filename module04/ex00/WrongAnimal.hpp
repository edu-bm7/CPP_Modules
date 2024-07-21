#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
public:
	WrongAnimal();                         // Canonical Default Constructor
	WrongAnimal(WrongAnimal const& other); // Canonical Copy Constructor
	virtual ~WrongAnimal();                // Canonical Default Destructor

	WrongAnimal& operator=(WrongAnimal const& rhs); // Canonical Assignment Operator

	void makeSound() const;
	std::string getType() const;

protected:
	std::string mType;
};

#endif // WRONGANIMAL_HPP

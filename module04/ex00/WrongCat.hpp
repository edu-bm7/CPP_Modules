#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal {
public:
	WrongCat();                      // Canonical Default Constructor
	WrongCat(WrongCat const& other); // Canonical Copy Constructor
	~WrongCat();                     // Canonical Default Destructor

	WrongCat& operator=(WrongCat const& rhs); // Canonical Assignment Operator
	void makeSound() const;
	std::string getType() const;
};

#endif // WRONGCAT_HPP

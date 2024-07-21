#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <cstdlib>
#include <iostream>
#include <string>

#define MAX_IDEAS 100

class Brain {
public:
	Brain();                   // Canonical Default Constructor
	Brain(Brain const& other); // Canonical Copy Constructor
	~Brain();                  // Canonical Default Destructor

	Brain& operator=(Brain const& rhs); // Canonical Assignment Operator

	std::string getIdea(size_t const idx) const;
	void setIdea(size_t const idx, std::string idea);

protected:
	std::string mIdeas[MAX_IDEAS];
};

std::ostream& operator<<(std::ostream& os, Brain const& brain);

#endif // BRAIN_HPP

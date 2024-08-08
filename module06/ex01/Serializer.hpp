#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer {
public:
	~Serializer();                                // Canonical Default Destructor
	Serializer& operator=(const Serializer& rhs); // Canonical Assignment Operator

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer();                        // Canonical Default Constructor
	Serializer(const Serializer& other); // Canonical Copy Constructor
};

#endif // SERIALIZER_HPP

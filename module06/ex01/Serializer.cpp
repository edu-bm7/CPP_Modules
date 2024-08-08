#include "Serializer.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Serializer::Serializer()
{
	return;
}

Serializer::Serializer(const Serializer& rhs)
{
	*this = rhs;
	return;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

Serializer::~Serializer()
{
	return;
}

/*--------------------------------OVERLOADS-----------------------------------*/

Serializer& Serializer::operator=(const Serializer& rhs)
{
	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}
	return *this;
}

/*----------------------------------METHODS-----------------------------------*/

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

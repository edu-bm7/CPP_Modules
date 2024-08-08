#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

template<typename T>
class Array {
public:
	Array();                   // Canonical Default Constructor
	Array(const Array& other); // Canonical Copy Constructor
	~Array();                  // Canonical Default Destructor

	Array(unsigned int n);
	Array& operator=(const Array& rhs); // Canonical Assignment Operator
	T& operator[](const unsigned int index) const;

	unsigned int size() const;

private:
	T* mElements;
	unsigned int mSize;
};

#include "Array.tpp"

#endif // ARRAY_HPP

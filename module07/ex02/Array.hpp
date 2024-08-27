#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <iostream>
#include <stdexcept>

template< typename T >
class Array {
public:
	// Canonical Default Constructor
	Array() : mElements(NULL), mSize(0)
	{
		std::cout << "Empty Array Created." << std::endl;
	}

	// Canonical Default Copy Constructor
	Array(const Array< T >& other) : mElements(NULL), mSize(other.mSize)
	{
		if (!mSize) {
			return;
		}

		mElements = new T[mSize];
		for (unsigned int i = 0; i < mSize; ++i) {
			mElements[i] = other.mElements[i];
		}
		std::cout << "Elements of array deep copied via Copy Constructor." << std::endl;
	}

	// Canonical Default Destructor
	~Array()
	{
		if (mElements) {
			delete[] mElements;
		}
		std::cout << "Array Destructor called." << std::endl;
	}

	// Parameterized Constructor
	Array(unsigned int n) : mElements(NULL), mSize(n)
	{
		if (!n) {
			return;
		}

		mElements = new T[mSize]();
		std::cout << "Array with " << mSize
				  << " elements has been created and initialized." << std::endl;
	}

	// Canonical Assignment Operator
	Array< T >& operator=(const Array< T >& rhs)
	{
		// Guard Self-Assignment
		if (this == &rhs) {
			return *this;
		}

		if (mElements || !rhs.mSize) {
			delete[] mElements;
			if (!rhs.mSize) {
				mSize = 0;
				return *this;
			}
		}
		mSize = rhs.mSize;
		mElements = new T[mSize];
		for (unsigned int i = 0; i < mSize; ++i) {
			mElements[i] = rhs.mElements[i];
		}
		std::cout << "Array Construction done by Assignment Operator." << std::endl;
	}

	// Subscript Operator Overload
	const T& operator[](unsigned int index) const
	{
		if (index >= mSize) {
			throw std::out_of_range("Array Index out of bounds");
		}
		return mElements[index];
	}

	T& operator[](unsigned int index)
	{
		if (index >= mSize) {
			throw std::out_of_range("Array Index out of bounds");
		}
		return mElements[index];
	}


	// Getter Member Function
	unsigned int size() const
	{
		return mSize;
	}

private:
	T* mElements;
	unsigned int mSize;
};

#endif // ARRAY_HPP

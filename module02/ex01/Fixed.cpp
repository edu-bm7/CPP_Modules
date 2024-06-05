#include "Fixed.hpp"
#include <cmath>
#include <iostream>
/* Uncomment this include statment to use std::setprecision(n) */
// #include <iomanip>

Fixed::Fixed() : mRawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : mRawBits(value << mskBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : mRawBits(roundf(value * (1 << mskBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;

	// Guard Self-assignment
	if (this == &rhs) {
		return *this;
	}

	mRawBits = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return mRawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	mRawBits = raw;
}

float Fixed::toFloat() const
{
	return mRawBits / static_cast<float>(1 << mskBits);
}

int Fixed::toInt() const
{
	return mRawBits >> mskBits;
}

std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
	/* Uncoment the line bellow and comment the original statment to check the 
	 * whole fixed number precision without rounded numbers
	 * */
	// os << std::setprecision(8) << fixed.toFloat();
	os << fixed.toFloat();
	return os;
}

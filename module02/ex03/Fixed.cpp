#include "Fixed.hpp"
#include <cmath>
#include <iostream>
/* Uncomment this include statment to use std::setprecision(n) */
// #include <iomanip>

Fixed::Fixed() : mRawBits(0)
{
	return;
}

Fixed::Fixed(int const value) : mRawBits(value << mskBits)
{
	return;
}

Fixed::Fixed(float const value) : mRawBits(roundf(value * (1 << mskBits)))
{
	return;
}

Fixed::Fixed(Fixed const& other)
{
	*this = other;
}

Fixed::~Fixed()
{
	return;
}

// Overload Operators
Fixed& Fixed::operator=(Fixed const& rhs)
{
	// Guard self-assignment
	if (this == &rhs) {
		return *this;
	}

	mRawBits = rhs.getRawBits();
	return *this;
}

bool Fixed::operator<(Fixed const& rhs) const
{
	return getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>(Fixed const& rhs) const
{
	return rhs < *this;
}

bool Fixed::operator<=(Fixed const& rhs) const
{
	return !(*this > rhs);
}

bool Fixed::operator>=(Fixed const& rhs) const
{
	return !(*this < rhs);
}

bool Fixed::operator==(Fixed const& rhs) const
{
	return getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const& rhs) const
{
	return !(*this == rhs);
}

Fixed Fixed::operator+(Fixed const& rhs) const
{
	return Fixed(getRawBits() + rhs.getRawBits());
}

Fixed Fixed::operator-(Fixed const& rhs) const
{
	return Fixed(getRawBits() - rhs.getRawBits());
}

Fixed Fixed::operator*(Fixed const& rhs) const
{
	long long result = static_cast<long long>(getRawBits() * static_cast<long long>(rhs.getRawBits()));
	result >>= mskBits;
	return Fixed(result / static_cast<float>(1 << mskBits));
}

Fixed Fixed::operator/(Fixed const& rhs) const
{
	if (rhs.getRawBits() == 0) {
		throw std::runtime_error("Error: Division by zero");
	}
	long long numerator = static_cast<long long>(getRawBits() << mskBits);
	long long denominator = static_cast<long long>(rhs.getRawBits());
	long long result = numerator / denominator;
	return Fixed(result / static_cast<float>(1 << mskBits));
}

Fixed& Fixed::operator++()
{
	setRawBits(getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	++(*this);
	return old;
}

Fixed& Fixed::operator--()
{
	setRawBits(getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	--(*this);
	return old;
}

// Member functions
float Fixed::toFloat() const
{
	return mRawBits / static_cast<float>(1 << mskBits);
}

int Fixed::toInt() const
{
	return mRawBits >> mskBits;
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs)
{
	return lhs < rhs ? lhs : rhs;
}

Fixed const& Fixed::min(Fixed const& lhs, Fixed const& rhs)
{
	return lhs < rhs ? lhs : rhs;
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
	return lhs > rhs ? lhs : rhs;
}

Fixed const& Fixed::max(Fixed const& lhs, Fixed const& rhs)
{
	return lhs > rhs ? lhs : rhs;
}

// Getter and Setters
int Fixed::getRawBits() const
{
	return mRawBits;
}

void Fixed::setRawBits(int const raw)
{
	mRawBits = raw;
}

// ostream operator overload
std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
	/* Uncoment the line bellow and comment the original statment to check the 
	 * whole fixed number precision without rounded numbers
	 * */
	// os << std::setprecision(8) << fixed.toFloat();
	os << fixed.toFloat();
	return os;
}

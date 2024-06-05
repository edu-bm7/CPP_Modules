#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed(); // Canonical Default Constructor
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const& other); // Canonical Copy Constructor
	~Fixed();                  // Canonical Default Destructor

	// Operators Overload:
	Fixed& operator=(Fixed const& rhs); // Canonical Assignment Operator
	bool operator<(Fixed const& rhs) const;
	bool operator>(Fixed const& rhs) const;
	bool operator<=(Fixed const& rhs) const;
	bool operator>=(Fixed const& rhs) const;
	bool operator==(Fixed const& rhs) const;
	bool operator!=(Fixed const& rhs) const;
	Fixed operator+(Fixed const& rhs) const;
	Fixed operator-(Fixed const& rhs) const;
	Fixed operator*(Fixed const& rhs) const;
	Fixed operator/(Fixed const& rhs) const;
	// We use an Unnamed Variable so we can differentiate between postfix/prefix
	// The int variable is never used
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();   // Prefix decrement operator
	Fixed operator--(int); // Postfix decrement operator


	// Member Functions:
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
	static Fixed& min(Fixed& lhs, Fixed& rhs);
	static Fixed const& min(Fixed const& lhs, Fixed const& rhs);
	static Fixed& max(Fixed& lhs, Fixed& rhs);
	static Fixed const& max(Fixed const& lhs, Fixed const& rhs);

private:
	int mRawBits;
	static const int mskBits = 8;
};

std::ostream& operator<<(std::ostream& os, Fixed const& fixed);

#endif // FIXED_HPP

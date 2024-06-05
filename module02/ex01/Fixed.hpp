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

	Fixed& operator=(Fixed const& rhs); // Canonical Assignment Operator

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;

private:
	int mRawBits;
	static const int mskBits = 8;
};

std::ostream& operator<<(std::ostream& os, Fixed const& fixed);

/* @NOTE: Instructions on how the calculation of the fixed point number can
 * 	be done in our calculator:
 *
 * 	1. Open your calculator and select either advanced or programming mode:
 * 	2. When we are dealing with bit shifting, 
 * 		to right shift '>>' means: value >> k = value / (2^k);
 * 		while to left shift '<<' means value << k = value * 2^k;
 * 	3. Calculating the fixed point binary representation of a float number:
 * 		- We multiply the number by the number of bits that our fixed,
 * 		point number will have as precision.
 * 		since we can't use bitwise operations on float numbers
 * 		: float value * (1 << Bits) = value * (2^Bits);
 * 		- This number that we got, will have it's binary representation in our
 * 		calculator. e.g. 42.42 * (2^8) ~= rounf(10859.52) = 10860.0  = 0010101001101100.
 * 		- Now note, when saying we have 8 bits of precision simply means that
 * 		the fractional part of our binary number will be in the 8th position
 * 		from the least significant bit(LSB): 00101010.01101100
 * 		Now anything represented after the fixed point will be calculated from left to right;
 * 		2^(-k). Then our 10860.0(42.42) float point will have a fractional part consistent of:
 * 		0*(1/2) + 1*(1/4) + 1*(1/8) + 0*(1/16) + 1*(1/32) + 1*(1/64) + 0*(1/128) + 0*(1/256)
 * 		so our fractional part is 0.421875! And our decimal part will be:
 * 		0*(2^0) + 1*(2^1) + 0*(2^2) + 1*(2^3) + 0*(2^4) + 1*(2^5) + 0*(2^6) + 0*(2^7) = 42!!
 * 		so our number is the fractional part + the deciaml part
 * 		= 42 + 0.421875 = 42.421875! 
 * 		@NOTE: But why does it prints 42.4219 on std::cout ?
 *
 * 		That's because we didn't set the precision on the output string,
 * 		so it's rounded to the nearest value, defined by a default precision.
 * 		On out Fixed.cpp there is a command to make the precision = 8,
 * 		that's the biggest precision we can have with 8bits mskBits(8bits for the fractional part)!
 *		You can try change these values and see with your calculator if the numbers add's up.
 *		Remember, with fixed point numbers we always will have the same amount of bits
 *		for our fractional part, meaning we loose range in the decimal part.
 *		so to represent a really big number stored in a int fixed point notation, we need to reduce
 *		our precision bits, which will make some fractional numbers unable to be expressed.
 *		
 * */

#endif // FIXED_HPP

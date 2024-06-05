#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
	Fixed();                   // Canonical Default Constructor
	Fixed(Fixed const& other); // Canonical Copy Constructor
	~Fixed();                  // Canonical Default Destructor

	Fixed& operator=(Fixed const& rhs); // Canonical Assignment Operator
	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int mRawBits;
	static const int mskBits = 8;
};

#endif // FIXED_HPP

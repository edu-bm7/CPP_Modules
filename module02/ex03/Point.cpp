#include "Point.hpp"

Point::Point() : mX(0), mY(0)
{
	return;
}

Point::Point(float const x, float const y) : mX(x), mY(y)
{
	return;
}

Point::Point(Point const& other)
{
	*this = other;
	return;
}

Point& Point::operator=(Point const& rhs)
{
	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}
	const_cast<Fixed&>(mX) = rhs.getX();
	const_cast<Fixed&>(mY) = rhs.getY();
	return *this;
}

Fixed Point::getX() const
{
	return mX;
}

Fixed Point::getY() const
{
	return mY;
}

int Point::getBits()
{
	return mskBits;
}

Point::~Point()
{
	return;
}

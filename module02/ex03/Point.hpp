#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
	Point();
	Point(float const x, float const y);
	Point(Point const& other);
	~Point();

	Point& operator=(Point const& rhs);
	Fixed getX() const;
	Fixed getY() const;
	static int getBits();

private:
	Fixed const mX;
	Fixed const mY;
	static const int mskBits = 8;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP

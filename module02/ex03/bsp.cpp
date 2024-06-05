#include "Point.hpp"
#include <cstdlib>

static float triangle_area(Point a, Point b, Point c)
{
	// area = abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0;
	float area = a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) + b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) + c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat());
	return std::abs(area) / 2.0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float totalArea = triangle_area(a, b, c);

	float subArea1 = triangle_area(point, a, b);
	float subArea2 = triangle_area(point, b, c);
	float subArea3 = triangle_area(point, c, a);

	float epsilon = 1.0f / static_cast<float>(1 << Point::getBits());

	std::cout << "x1: " << a.getX() << " y1: " << a.getY() << std::endl;
	std::cout << "x2: " << b.getX() << " y2: " << b.getY() << std::endl;
	std::cout << "x3: " << c.getX() << " y3: " << c.getY() << std::endl;
	std::cout << "x : " << point.getX() << " y:  " << point.getY() << std::endl;
	std::cout << "subArea1: " << subArea1 << " subArea2: " << subArea2
			  << " subArea3: " << subArea3 << " TotalArea: " << totalArea << std::endl;

	if (subArea1 > epsilon && subArea2 > epsilon && subArea3 > epsilon && std::abs((subArea1 + subArea2 + subArea3) - totalArea) < epsilon) {
		return true;
	}
	return false;
}

#include "Point.hpp"
#include <iostream>

// Color codes
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"

Point createPoint(float x, float y)
{
	return Point(x, y);
}

void printResult(std::string test, bool passed)
{
	if (passed) {
		std::cout << GREEN << test << ": Passed" << RESET << std::endl;
	} else {
		std::cout << RED << test << ": Failed" << RESET << std::endl;
	}
}

void testInsideTriangle()
{
	Point a = createPoint(0, 0);
	Point b = createPoint(1, 0);
	Point c = createPoint(0, 1);
	Point p = createPoint(0.1, 0.1);

	printResult("Test Inside Triangle", bsp(a, b, c, p));
}

void testOnEdge()
{
	Point a = createPoint(0, 0);
	Point b = createPoint(1, 0);
	Point c = createPoint(0, 1);
	Point p = createPoint(0.5, 0.5); // On the line connecting b and c

	printResult("Test On Edge", !bsp(a, b, c, p));
}

void testOnVertex()
{
	Point a = createPoint(0, 0);
	Point b = createPoint(1, 0);
	Point c = createPoint(0, 1);
	Point p = createPoint(0, 0); // Exactly at vertex a

	printResult("Test On Vertex", !bsp(a, b, c, p));
}

void testOutsideTriangle()
{
	Point a = createPoint(0, 0);
	Point b = createPoint(1, 0);
	Point c = createPoint(0, 1);
	Point p = createPoint(1, 1); // Clearly outside the triangle

	printResult("Test Outside Triangle", !bsp(a, b, c, p));
}

void testDegenerateCase()
{
	Point a = createPoint(0, 0);
	Point b = createPoint(0, 0);
	Point c = createPoint(0, 0);
	Point p = createPoint(0, 0); // Degenerate triangle where all points are the same

	printResult("Test Degenerate Case", !bsp(a, b, c, p));
}

int main()
{
	testInsideTriangle();
	testOnEdge();
	testOnVertex();
	testOutsideTriangle();
	testDegenerateCase();

	return 0;
}
